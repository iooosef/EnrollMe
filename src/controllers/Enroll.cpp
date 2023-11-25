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
    LogSession(thisapp);
}


void Enroll::StuLvl(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/type")(
        [&](const crow::request& req) {
            auto& session = thisapp.get_context<Session>(req);
            crow::response page(200);
            auto keys = session.keys();
            for (const auto& key : keys)
            {
                // .string(key) converts a value of any type to a string
                session.remove(key);
            }
            session.set("stu_type", "");
            page.set_static_file_info("templates/stuLvl.html");
            page.set_header("Content-Type", "text/html");
            return page;
        });
}

void Enroll::StuLvl_Elem(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/type/elementary")(
        [&](const crow::request& req, crow::response& res) {
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_type", "elem");
            res.redirect("/enroll/form");
            res.end();
        });
}

void Enroll::StuLvl_Jhs(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/type/jhs")(
        [&](const crow::request& req, crow::response& res) {
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_type", "jhs");
            res.redirect("/enroll/form");
            res.end();
        });
}

void Enroll::StuLvl_Shs(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/type/shs")(
        [&](const crow::request& req, crow::response& res) {
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_type", "shs");
            res.redirect("/enroll/form");
            res.end();
        });
}

void Enroll::StuLvl_College(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/enroll/type/college")(
        [&](const crow::request& req, crow::response& res) {
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_type", "college");
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

void Enroll::LogSession(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/log/session")(
        [&](const crow::request& req) {
            auto& session = thisapp.get_context<Session>(req);
            auto keys = session.keys();

            std::string existing_keys;
            for (const auto& key : keys)
            {
                // .string(key) converts a value of any type to a string
                existing_keys += "<p> " + key + " = " + session.string(key) + "</p>";
            }

            return existing_keys;
        });
}
// add page for logging of  sessions