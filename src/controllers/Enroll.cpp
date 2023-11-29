#include "Enroll.h"


Enroll::Enroll()
{
	//ctor
}


void Enroll::include_routes(crow::App<crow::CookieParser, Session>& thisapp)
{
    StuLvl(thisapp);
    StuLvl_Elem(thisapp);
    StuLvl_Jhs(thisapp);
    StuLvl_Shs(thisapp);
    StuLvl_College(thisapp);

    StuProgram(thisapp);
    StuProgramPOST(thisapp);

    StuType(thisapp);
    StuType_NewStu(thisapp);
    StuType_Freshmen(thisapp);
    StuType_Transferee(thisapp);
    StuType_Shiftee(thisapp);
    StuType_OldStu(thisapp);

    EnrollForm(thisapp);
    EnrollFormPOST(thisapp);

    CoursesForm(thisapp);
    CoursesFormPOST(thisapp);

    EnrollInsert(thisapp);

    EnrollSummary(thisapp);

    testHTMX(thisapp);
    getNationalities(thisapp);
    getCountries(thisapp);
    getCourses(thisapp);
    getCoursesSummary(thisapp);
}


void Enroll::StuLvl(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/level").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            auto& session = thisapp.get_context<Session>(req);
            crow::response page(200);

            ClearSession(thisapp, req);

            session.set("stu_lvl", "");
            page.set_static_file_info("templates/stuLvl.html");
            page.set_header("Content-Type", "text/html");
            return page;
        });
}

void Enroll::StuLvl_Elem(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/level/elementary").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response res;
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_lvl", "elem");
            res.redirect("/enroll/type");
            return res;
        });
}

void Enroll::StuLvl_Jhs(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/level/jhs").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response res;
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_lvl", "jhs");
            res.redirect("/enroll/type");
            return res;
        });
}

void Enroll::StuLvl_Shs(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/level/shs").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response res;
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_lvl", "shs");
            res.redirect("/enroll/program");
            return res;
        });
}

void Enroll::StuLvl_College(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/level/college").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response res;
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_lvl", "college");
            res.redirect("/enroll/program");
            return res;
        });
}


void Enroll::StuProgram(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/program").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response page(200);
            auto& session = thisapp.get_context<Session>(req);
            std::string stu_lvl = session.string("stu_lvl");

            if (stu_lvl == "shs") {
                page.set_static_file_info("templates/stuProgram-shs.html");
                page.set_header("Content-Type", "text/html");
                return page;
            }
            else {
                page.set_static_file_info("templates/stuProgram-college.html");
                page.set_header("Content-Type", "text/html");
                return page;
            }
        });
}
void Enroll::StuProgramPOST(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/program/submit").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response res;
            std::cout << "POST /enroll/program\n";
            auto& session = thisapp.get_context<Session>(req);
            //auto formSubmission = req.get_body_params();
            session.set("enrll_program", req.url_params.get("enrll_program"));
            res.redirect("/enroll/type");
            return res;
        });
}

void Enroll::StuType(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/type").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response page(200);
            auto& session = thisapp.get_context<Session>(req);
            std::string stu_lvl = session.string("stu_lvl");

            if (stu_lvl == "elem" || stu_lvl == "jhs" || stu_lvl == "shs") {
                page.set_static_file_info("templates/stuType-gen.html");
                page.set_header("Content-Type", "text/html");
                return page;
            }
			else if (stu_lvl == "college") {
                page.set_static_file_info("templates/stuType-college.html");
                page.set_header("Content-Type", "text/html");
			}
			else {
				page.redirect("/enroll/level");
			}
            return page;
        });
}

void Enroll::StuType_NewStu(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/type/newStu").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response res;
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_type", "newStu");
            res.redirect("/enroll/form");
            return res;
        });
}

void Enroll::StuType_Freshmen(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/type/freshmen").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response res;
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_type", "freshmen");
            res.redirect("/enroll/form");
            return res;
        });
}

void Enroll::StuType_Transferee(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/type/transferee").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response res;
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_type", "transferee");
            res.redirect("/enroll/form");
            return res;
        });
}

void Enroll::StuType_Shiftee(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/type/shiftee").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response res;
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_type", "shiftee");
            res.redirect("/enroll/form");
            return res;
        });
}

void Enroll::StuType_OldStu(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/type/oldStu").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response res;
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_type", "oldStu");
            res.redirect("/enroll/form");
            return res;
        });
}

void Enroll::EnrollForm(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/form").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response page(200);
            auto& session = thisapp.get_context<Session>(req);
            std::string stu_type = session.string("stu_type");
            if (stu_type == "oldStu" || stu_type == "shiftee") {
                page.set_static_file_info("templates/EnrollmentForm-StuNum.html");
            } 
            else {
                page.set_static_file_info("templates/EnrollmentForm.html");
            }
            page.set_header("Content-Type", "text/html");
            return page;
        });
}
// Confirm Page
void Enroll::EnrollFormPOST(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/form").methods(crow::HTTPMethod::POST)(
        [&](const crow::request& req) {
            auto page = crow::mustache::load("FormConfirm.html");
            auto& session = thisapp.get_context<Session>(req);
            std::string stu_type = session.string("stu_type");
            std::string stu_lvl = session.string("stu_lvl");
            auto formSubmission = req.get_body_params();
            std::string fields[30] = {"enrll_firstName", "enrll_midName", "enrll_lastName", "enrll_suffixName", 
                                      "enrll_sex", "enrll_DoB", "enrll_PoB", "enrll_religion", "enrll_nationality", "enrll_civilStatus",
                                      "enrll_country", "enrll_province", "enrll_cityMun", "enrll_brgy", "enrll_zipCode", "enrll_addrLine", 
                                      "enrll_mobileNumber", "enrll_telephoneNumber", "enrll_email", 
                                      "grdn_firstName", "grdn_midName", "grdn_lastName", "grdn_suffixName", "grdn_sex", "grdn_relation",
                                      "grdn_address", "grdn_mobileNumber", "grdn_telephoneNumber", "grdn_email"
                                     };

            crow::json::wvalue mustacheMappings;

            for (int x = 0; x < 29; x++) {
				mustacheMappings[fields[x]] = formSubmission.get(fields[x]);
                session.set(fields[x], formSubmission.get(fields[x]));
			}

            if (stu_type == "oldStu" || stu_type == "shiftee")
            {
                page = crow::mustache::load("FormConfirm-StuNum.html");
                mustacheMappings["student_number"] = formSubmission.get("student_number");
                session.set("student_number", formSubmission.get("student_number"));
            }

            crow::mustache::context ctx (mustacheMappings);
            return page.render(ctx);
        });
}

void Enroll::CoursesForm(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/courses").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
			crow::response page(200);
			auto& session = thisapp.get_context<Session>(req);
			std::string stu_type = session.string("stu_type");
			std::string stu_lvl = session.string("stu_lvl");
			std::string stu_program = session.string("enrll_program");
            if (stu_type == "shiftee" || stu_type == "transferee") {
				page.set_static_file_info("templates/CoursesForm-ReToRegistrar.html");
			}
            else{
				page.set_static_file_info("templates/CoursesForm.html");
			}
			page.set_header("Content-Type", "text/html");
			return page;
		});
}
void Enroll::CoursesFormPOST(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/coursesPOST").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response res;
            Database EnrollMeDb("./data/EnrollMe.db");
            auto& session = thisapp.get_context<Session>(req);
            auto formSubmission = req.url_params.get_list("course", false);
            const std::string SCHOOL_YEAR = "2023-2024";
            const std::string SEMESTER = "1";
            std::string courses_str = "";
            std::string course_str;

            std::vector<std::string> columns = { "enrll_transactionId", "student_number", "enrll_program", "enrll_schoolYear", 
                                                "enrll_type", "enrll_semester", "course_code" };
            std::vector<std::string> values;

            if (EnrollMeDb.openDB())
            {
                for (const auto& course : formSubmission)
                {
                    std::cout << course << std::endl;
                    courses_str += course;
                    courses_str += ",";
                    course_str = course;
                    values = { session.string("enrll_transactionId"), session.string("student_number"), session.string("enrll_program"),
                                SCHOOL_YEAR, session.string("stu_type"), SEMESTER, course_str };
                    if (!EnrollMeDb.executeInsert("tbl_college_class_enroll", columns, values))
                    {
                        std::cout << "Error inserting data to Database.\n";
                    }
                }
            }
            else {
                std::cerr << "Failed to open the database." << std::endl;
            }
            EnrollMeDb.closeDB();


            if (formSubmission.size() != 0)
            {
                courses_str.pop_back();
			}

            session.set("courses", courses_str);
            res.redirect("/enroll/summary");
            return res;
        });
}

void Enroll::EnrollInsert(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/dbInsert").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response res;
            auto& session = thisapp.get_context<Session>(req);
            Database EnrollMeDb("./data/EnrollMe.db");
            const std::string SCHOOL_YEAR = "2023-2024";
            const std::string SEMESTER = "1";
            const std::string TRANSACTION_ID = generateShortUUID();

            std::string tableName = "tbl_enrollees";
            std::vector<std::string> columns = { "enrll_transactionId", "enrll_type", "enrll_level", "enrll_schoolYear", "enrll_semester", 
                                                 "enrll_firstName", "enrll_midName", "enrll_lastName", "enrll_suffixName",
                                                 "enrll_sex", "enrll_DoB", "enrll_PoB", "enrll_religion", "enrll_nationality", "enrll_civilStatus",
                                                 "enrll_country", "enrll_province", "enrll_cityMun", "enrll_brgy", "enrll_zipCode", "enrll_addrLine",
                                                 "enrll_mobileNumber", "enrll_telephoneNumber", "enrll_email",
                                                 "grdn_firstName", "grdn_midName", "grdn_lastName", "grdn_suffixName", "grdn_sex", "grdn_relation",
                                                 "grdn_address", "grdn_mobileNumber", "grdn_telephoneNumber", "grdn_email" };
            std::vector<std::string> values = { TRANSACTION_ID, session.string("stu_type"), session.string("stu_lvl"), SCHOOL_YEAR, SEMESTER,
                                                 session.string("enrll_firstName"), session.string("enrll_midName"), session.string("enrll_lastName"), 
                                                 session.string("enrll_suffixName"), session.string("enrll_sex"), session.string("enrll_DoB"), 
                                                 session.string("enrll_PoB"), session.string("enrll_religion"), session.string("enrll_nationality"), 
                                                 session.string("enrll_civilStatus"),
                                                 session.string("enrll_country"), session.string("enrll_province"), session.string("enrll_cityMun"), 
                                                 session.string("enrll_brgy"), session.string("enrll_zipCode"), session.string("enrll_addrLine"),
                                                 session.string("enrll_mobileNumber"), session.string("enrll_telephoneNumber"), session.string("enrll_email"),
                                                 session.string("grdn_firstName"), session.string("grdn_midName"), session.string("grdn_lastName"), 
                                                 session.string("grdn_suffixName"), session.string("grdn_sex"), session.string("grdn_relation"),
                                                 session.string("grdn_address"), session.string("grdn_mobileNumber"), session.string("grdn_telephoneNumber"), 
                                                 session.string("grdn_email")
                                              };

            if (session.string("stu_type") == "oldStu" || session.string("stu_type") == "shiftee")
            {
				columns.push_back("student_number");
				values.push_back(session.string("student_number"));
			}

            if (session.string("stu_lvl") == "shs" || session.string("stu_lvl") == "college")
			{ 
            	columns.push_back("enrll_program");
                values.push_back(session.string("enrll_program"));
            }

            if (EnrollMeDb.openDB())
            {
                if (!EnrollMeDb.executeInsert(tableName, columns, values))
                {
					std::cout << "Error inserting data to Database.\n";
				}
            }
            else {
                std::cerr << "Failed to open the database." << std::endl;
            }
            EnrollMeDb.closeDB();

            session.set("enrll_transactionId", TRANSACTION_ID);

            if (session.string("stu_type") == "shiftee" || session.string("stu_type") == "transferee")
            {
                res.redirect("/enroll/college/courses/shiftran");
            }
            else if (session.string("stu_type") == "freshmen")
            {
                res.redirect("/enroll/college/courses/freshmen");
            }
            else if (session.string("stu_type") == "oldStu")
            {
                res.redirect("/enroll/college/courses/oldStu");
            }
            else
            {
				res.redirect("/enroll/summary");
			}
            return res;
        }
    );
}

void Enroll::EnrollSummary(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/summary").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            auto page = crow::mustache::load("EnrollSummary.html");
            auto& session = thisapp.get_context<Session>(req);
            const std::string stu_type = (session.string("stu_type") == "oldStu") ? "old student" 
                                        : (session.string("stu_type") == "newStu") ? "new student" : "";
            const std::string stu_lvl = (session.string("stu_lvl") == "elem") ? "elementary"
                                        : (session.string("stu_lvl") == "jhs") ? "junior high school"
                                        : (session.string("stu_lvl") == "shs") ? "senior high school" : "";
            const std::string stu_number = session.string("student_number");
            const std::string stu_program = session.string("enrll_program");
            const std::string SCHOOL_YEAR = "2023-2024";
            const std::string SEMESTER = "1";
            crow::json::wvalue mustacheMappings;
            std::string fields[32] = { "enrll_transactionId", "enrll_firstName", "enrll_midName", "enrll_lastName", "enrll_suffixName",
                                      "enrll_sex", "enrll_DoB", "enrll_PoB", "enrll_religion", "enrll_nationality", "enrll_civilStatus",
                                      "enrll_country", "enrll_province", "enrll_cityMun", "enrll_brgy", "enrll_zipCode", "enrll_addrLine",
                                      "enrll_mobileNumber", "enrll_telephoneNumber", "enrll_email",
                                      "grdn_firstName", "grdn_midName", "grdn_lastName", "grdn_suffixName", "grdn_sex", "grdn_relation",
                                      "grdn_address", "grdn_mobileNumber", "grdn_telephoneNumber", "grdn_email"
            };


            for (int x = 0; x < 30; x++) {
                mustacheMappings[fields[x]] = session.get(fields[x], "");
            }
            mustacheMappings["student_number"] = stu_number;
            mustacheMappings["enrll_schoolYear"] = SCHOOL_YEAR;
            mustacheMappings["enrll_semester"] = SEMESTER;
            mustacheMappings["enrll_type"] = stu_type;
            mustacheMappings["enrll_level"] = stu_lvl;
            mustacheMappings["enrll_program"] = stu_program;


            crow::mustache::context ctx(mustacheMappings);
            return page.render(ctx);
        });

}

// HTMX ROUTES/METHODS

void Enroll::testHTMX(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/testHTMX").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response res;
            res.body = "<h1>test</h1><i>hello htmx!</i>";
            res.set_header("Content-Type", "text/html");
			return res;
		});
}

void Enroll::getNationalities(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/getNationalities").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
			crow::response res;
            Database OptionsDb("./data/OptionsProvider.db");
            std::string optionsHtml = "";
            if (OptionsDb.openDB())
            {
                std::string query = "SELECT * FROM tbl_nationalities;";
                std::vector<std::vector<std::string>> results = OptionsDb.executeSelect(query);
                for (const auto& row : results)
                {
                    optionsHtml += "<option value=\"" + row[1] + "\">" + row[1] + "</option>";
                }
            }
            res.body = optionsHtml;
            res.set_header("Content-Type", "text/html");
			return res;
		});
}

void Enroll::getCountries(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/getCountries").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
			crow::response res;
			Database OptionsDb("./data/OptionsProvider.db");
			std::string optionsHtml = "";
            if (OptionsDb.openDB())
            {
				std::string query = "SELECT code, name FROM tbl_countries;";
				std::vector<std::vector<std::string>> results = OptionsDb.executeSelect(query);
                for (const auto& row : results)
                {
					optionsHtml += "<option value=\"" + row[0] + "\">" + row[1] + "</option>";
				}
			}
			res.body = optionsHtml;
			res.set_header("Content-Type", "text/html");
			return res;
		});
}

void Enroll::getCourses(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/getCourses").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
			crow::response res;
            Database CoursesDb("./data/EnrollMe.db");
            auto& session = thisapp.get_context<Session>(req);
            const std::string stu_program = session.string("enrll_program");
            const std::string stu_number = session.string("student_number");
			std::string checkboxes = "";
            
            std::string eligibleCoursesQuery = "SELECT * FROM tbl_curriculum WHERE"
                                               "("
                                               "  ("
                                               "    (curriculum LIKE '" + stu_program + "%' OR curriculum = 'GenEd')"
                                               "    AND prerequisite = ''"
                                               "  )"
                                               "  AND course_code NOT IN"
                                               "    ("
                                               "      SELECT course_code FROM tbl_course_history WHERE "
                                               "      tbl_course_history.student_number = '" + stu_number + "' AND tbl_course_history.remarks = 'PASSED'"
                                               "    )"
                                               ") OR"
                                               "("
                                               "  ("
                                               "    (curriculum LIKE '" + stu_program + "%' OR curriculum = 'GenEd')"
                                               "    AND prerequisite IN"
                                               "    ("
                                               "      SELECT course_code FROM tbl_course_history WHERE "
                                               "      tbl_course_history.student_number = '" + stu_number + "' AND tbl_course_history.remarks = 'PASSED'"
                                               "    )"
                                               "  )"
                                               "  AND course_code NOT IN"
                                               "    ("
                                               "      SELECT course_code FROM tbl_course_history WHERE "
                                               "      tbl_course_history.student_number = '" + stu_number + "' AND tbl_course_history.remarks = 'PASSED'"
                                               "    )"
                                               ") LIMIT 16";

            if (CoursesDb.openDB())
            {
				std::vector<std::vector<std::string>> results = CoursesDb.executeSelect(eligibleCoursesQuery);
                if (results.empty())
                {
					std::cout << "No results found.\n";
				}
                CoursesDb.closeDB();

                for (const auto& row : results)
                {
                    std::cout << row[2] << " prereq: " << row[6] << std::endl;
                    int units = std::atoi(row[4].c_str()) + std::atoi(row[5].c_str());
                    std::string unit_str = std::to_string(units);

                    checkboxes = checkboxes + "<div class=\"checkbox-wrapper-16 w-100\">"
                                  "<label class=\"checkbox-wrapper w-100\">"
                                  "<input type=\"checkbox\" name=\"course\" value=\"" + row[2] + "\" class=\"checkbox-input\""
                                  "data-units=\"" + unit_str + "\" data-coreq=\"" + row[7] + "\"/>"
                                  "<span class=\"checkbox-tile\">"
                                  "<span class=\"checkbox-label\">" + row[2] + " - " + row[3] + " (" + unit_str + " units)" + "</span>"
                                  "</span>"
                                  "</label>"
                                  "</div>";
                }
			}
            res.body = checkboxes;
			res.set_header("Content-Type", "text/html");
			return res;
		});
}

void Enroll::getCoursesSummary(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/hxgetCourses").methods(crow::HTTPMethod::GET)(
        [&](const crow::request& req) {
            crow::response res;
            Database CoursesDb("./data/EnrollMe.db");
            auto& session = thisapp.get_context<Session>(req); 

            if (session.string("stu_lvl") != "college")
            {
				res.body = "";
				res.set_header("Content-Type", "text/html");
				return res;
			}

            const std::string courses = session.string("courses");

            std::vector<std::string> course_codes;
            std::string course_code = "";
            for (const auto& c : courses)
            {
                if (c == ',')
                {
					course_codes.push_back(course_code);
					course_code = "";
				}
                else
                {
					course_code += c;
				}
			}

            std::string coursesSummary = "";
			std::string query = "SELECT * FROM tbl_curriculum WHERE course_code = ";
            if (CoursesDb.openDB())
            {
                for (const auto& code : course_codes)
                {
					std::vector<std::vector<std::string>> results = CoursesDb.executeSelect(query + "'" + code + "';");
                    for (const auto& row : results)
                    {

                        int units = std::atoi(row[4].c_str()) + std::atoi(row[5].c_str());
                        std::string unit_str = std::to_string(units);

                        coursesSummary = coursesSummary + "<table cellpadding=\"0\" cellspacing=\"0\" class=\"col\">"
								  "<tbody>"
								  "<tr class=\"heading\">"
								  "<td class=\"col-2 text-start\">Course Code</td>"
								  "<td class=\"col-9 text-center\">Course Title</td>"
								  "<td class=\"col-1 text-end\">Units</td>"
								  "</tr>"
								  "<tr class=\"details\">"
								  "<td class=\"text-start\">" + row[2] + "</td>"
								  "<td class=\"text-center\">" + row[3] + "</td>"
								  "<td class=\"text-end\">" + unit_str + "</td>"
								  "</tr>"
								  "</tbody>"
								  "</table>";


					}
				}
			}
			res.body = coursesSummary;
			res.set_header("Content-Type", "text/html");
			return res;
        }
    );
}

// MISC METHODS

void Enroll::ClearSession(crow::App<crow::CookieParser, Session>& thisapp, const crow::request& req)
{
    auto& session = thisapp.get_context<Session>(req);
    auto keys = session.keys();
    for (const auto& key : keys)
    {
        session.remove(key);
    }
}

std::string Enroll::generateShortUUID() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);

    const char* hex_chars = "0123456789abcdef";

    std::string shortUUID;

    for (int i = 0; i < 16; ++i) {
        shortUUID += hex_chars[dis(gen)];
    }

    return shortUUID;
}