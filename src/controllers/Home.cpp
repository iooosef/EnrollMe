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
        []() {
            crow::response page(200);
            page.set_static_file_info("templates/index.html");
            page.set_header("Content-Type", "text/html");
            return page;
        });
}