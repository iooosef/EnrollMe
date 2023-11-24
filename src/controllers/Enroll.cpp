#include "Enroll.h"


Enroll::Enroll()
{
	//ctor
}


void Enroll::include_routes(crow::App<crow::CookieParser, Session>& thisapp)
{
    test(thisapp);
}


void Enroll::test(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/test")(
        []() {
            crow::response myResponse(200, "<h1>test</h1><i>hello crow!</i>");
            myResponse.set_header("Content-Type", "text/html");
            myResponse.add_header("Custom-Header", "Custom-Value");
            return myResponse;
        });
}