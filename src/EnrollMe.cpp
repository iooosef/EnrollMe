#include "EnrollMe.h"

crow::response redirect()
{
    crow::response res;
    res.redirect("/");
    return res;
}

int main()
{
    using Session = crow::SessionMiddleware<crow::FileStore>;
    crow::App<crow::CookieParser, Session> EnrollMeApp
    {
        Session
        {
            // cookies cusomization
            crow::CookieParser::Cookie("session")
                .max_age(24 * 60 * 60) // 1 day
                .path("/"),
            4, // session Id length
            crow::FileStore{"/"}
        }
    };

    // Controller objects declaration
    Home home;
    Enroll enroll;
    
    initDb(); //initialize the database
    
    home.include_routes(EnrollMeApp);
    enroll.include_routes(EnrollMeApp);
    

    //set the port, set the app to run on multiple threads, and run the app
    EnrollMeApp.bindaddr("127.0.0.1")
        .port(18080)
        .multithreaded()
        .run_async();
}


//define your endpoint at the root directory
/*CROW_ROUTE(app, "/")([]() {
    return "Hello world";
    });

CROW_ROUTE(app, "/<string>")([](std::string name) {
    auto page = crow::mustache::load("index.html");
    crow::mustache::context ctx({ {"person", name} });
    return page.render(ctx);
    });

CROW_ROUTE(app, "/htmx/")(
    []() {
        crow::response myResponse(200, "<h1>test</h1><i>hello crow!</i>");
        myResponse.set_header("Content-Type", "text/html");
        myResponse.add_header("Custom-Header", "Custom-Value");
        return myResponse;
    });*/