// EnrollMe.cpp : Defines the entry point for the application.
//

#include "EnrollMe.h"

int main()
{
    crow::SimpleApp app; //define your crow application

    //define your endpoint at the root directory
    //CROW_ROUTE(app, "/")([]() {
    //    return "Hello world";
    //    });

    CROW_ROUTE(app, "/<string>")([](std::string name) { 
        auto page = crow::mustache::load("index.html");
        crow::mustache::context ctx({ {"person", name} }); 
        return page.render(ctx); 
        });

    //CROW_ROUTE(app, "/htmx/")(
    //    []() {
    //        crow::response myResponse(200, "<h1>test</h1><i>hello crow!</i>");  // Example constructor call
    //        myResponse.set_header("Content-Type", "text/html");
    //        myResponse.add_header("Custom-Header", "Custom-Value");
    //        return myResponse;
    //    });

    //set the port, set the app to run on multiple threads, and run the app
    app.bindaddr("127.0.0.1")
        .port(18080)
        .multithreaded()
        .run();
}