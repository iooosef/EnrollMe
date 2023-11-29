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
    EnrollForm(thisapp);
    EnrollFormPOST(thisapp);

    StuType(thisapp);
    StuType_NewStu(thisapp);
    StuType_Freshmen(thisapp);
    StuType_TranShft(thisapp);
    StuType_OldStu(thisapp);

    testHTMX(thisapp);
    getNationalities(thisapp);
    getCountries(thisapp);
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
            res.redirect("/enroll/type");
            res.end();
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
                return page;
			}
			else {
				page.redirect("/enroll/level");
				page.end();
			}
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

            page.set_static_file_info("templates/EnrollmentForm.html");
            page.set_header("Content-Type", "text/html");
            return page;
        });
}
void Enroll::EnrollFormPOST(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/form").methods(crow::HTTPMethod::POST)(
        [&](const crow::request& req) {
            crow::response page(200);
            auto& session = thisapp.get_context<Session>(req);

            auto formSubmission = req.get_body_params();
            char* enrll_lastName = formSubmission.get("enrll_lastName");
            std::string str(enrll_lastName);
            std::cout << formSubmission << std::endl;
            page.body = "<h1>POST</h1> <br/>" + str;
            page.set_header("Content-Type", "text/html");
            return page;
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