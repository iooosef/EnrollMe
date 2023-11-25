#include "Enroll.h"


Enroll::Enroll()
{
	//ctor
}


void Enroll::include_routes(crow::App<crow::CookieParser, Session>& thisapp)
{
    EnrollNow(thisapp);
}


void Enroll::EnrollNow(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/EnrollNow")(
        [&](const crow::request& req) {
            auto& session = thisapp.get_context<Session>(req);
            session.set("stu_type", "");

            crow::response page(200);
            page.set_static_file_info("templates/EnrollNow.html");
            page.set_header("Content-Type", "text/html");
            return page;
        });
}