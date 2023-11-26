#include "Home.h"

Home::Home()
{
	//ctor
}

void Home::include_routes(crow::App<crow::CookieParser, Session>& thisapp)
{
	index(thisapp);
}

void Home::index(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/")(
        [&](const crow::request& req) {
            crow::response page(200);
            page.set_static_file_info("templates/index.html");
            page.set_header("Content-Type", "text/html");
            ClearSession(thisapp, req);
            return page;
        });
}

void Home::ClearSession(crow::App<crow::CookieParser, Session>& thisapp, const crow::request& req)
{
    auto& session = thisapp.get_context<Session>(req);
    auto keys = session.keys();
    for (const auto& key : keys)
    {
        session.remove(key);
    }
}