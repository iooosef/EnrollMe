#include "Home.h"

Home::Home()
{
	//ctor
}

void Home::include_routes(crow::SimpleApp& thisapp)
{
	index(thisapp);
	about(thisapp);
}

void Home::index(crow::SimpleApp& thisapp)
{
	CROW_ROUTE(thisapp, "/")([]() {
		return "Hello world";
		});
}

void Home::about(crow::SimpleApp& thisapp)
{
    CROW_ROUTE(thisapp, "/htmx/")(
        []() {
            crow::response myResponse(200, "<h1>test</h1><i>hello crow!</i>");
            myResponse.set_header("Content-Type", "text/html");
            myResponse.add_header("Custom-Header", "Custom-Value");
            return myResponse;
        });
}