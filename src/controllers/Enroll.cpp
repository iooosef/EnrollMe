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
    StuType(thisapp);
    StuType_NewStu(thisapp);
    StuType_Freshmen(thisapp);
    StuType_TranShft(thisapp);
    StuType_OldStu(thisapp);
}


void Enroll::StuLvl(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/level")(
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
    CROW_ROUTE(thisapp, "/enroll/level/elementary")(
        [&](const crow::request& req, crow::response& res) {
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_lvl", "elem");
            res.redirect("/enroll/type");
            res.end();
        });
}

void Enroll::StuLvl_Jhs(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/level/jhs")(
        [&](const crow::request& req, crow::response& res) {
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_lvl", "jhs");
            res.redirect("/enroll/type");
            res.end();
        });
}

void Enroll::StuLvl_Shs(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/level/shs")(
        [&](const crow::request& req, crow::response& res) {
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_lvl", "shs");
            res.redirect("/enroll/type");
            res.end();
        });
}

void Enroll::StuLvl_College(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/level/college")(
        [&](const crow::request& req, crow::response& res) {
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_lvl", "college");
            res.redirect("/enroll/type");
            res.end();
        });
}

void Enroll::StuType(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/type")(
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
    CROW_ROUTE(thisapp, "/enroll/type/newStu")(
        [&](const crow::request& req, crow::response& res) {
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_type", "newStu");
            res.redirect("/enroll/form");
            res.end();
        });
}

void Enroll::StuType_Freshmen(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/type/freshmen")(
        [&](const crow::request& req, crow::response& res) {
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_type", "freshmen");
            res.redirect("/enroll/form");
            res.end();
        });
}

void Enroll::StuType_TranShft(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/type/tranShft")(
        [&](const crow::request& req, crow::response& res) {
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_type", "tranShft");
            res.redirect("/enroll/form");
            res.end();
        });
}

void Enroll::StuType_OldStu(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/type/oldStu")(
        [&](const crow::request& req, crow::response& res) {
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_type", "oldStu");
            res.redirect("/enroll/form");
            res.end();
        });
}

void Enroll::EnrollForm(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/form")(
        [&](const crow::request& req) {
            crow::response page(200);
            auto& session = thisapp.get_context<Session>(req);

            page.set_static_file_info("templates/EnrollmentForm.html");
            page.set_header("Content-Type", "text/html");
            return page;
        });
}

void Enroll::ClearSession(crow::App<crow::CookieParser, Session>& thisapp, const crow::request& req)
{
    auto& session = thisapp.get_context<Session>(req);
    auto keys = session.keys();
    for (const auto& key : keys)
    {
        session.remove(key);
    }
}