#include "EnrollMe.h"

crow::response redirect()
{
    crow::response res;
    res.redirect("/");
    return res;
}

int main(int argc, char* argv[])
{
    const char* dbPath = "./data/EnrollMe.db";
    if (argc >= 2)
    {
        if (strcmp(argv[1], "initdb") == 0)
        {
            // initialize the database
            Database EnrollMeDb(dbPath);
            if (EnrollMeDb.openDB())
            {
                if (EnrollMeDb.initEnrollMeTables())
                {
					std::cout << "EnrollMe database initialized successfully." << std::endl;
                    EnrollMeDb.closeDB();
					return 0;
				}
                EnrollMeDb.closeDB();
            }
			return 0;
		}
        else if (strcmp(argv[1], "load-curriculum") == 0)
        {
			// seed the database
			Database EnrollMeDb(dbPath);
            if (EnrollMeDb.openDB())
            {
				if (EnrollMeDb.loadCurriculum())
				{
                    std::cout << "The \"tbl_curriculum.csv\" has been loaded into database successfully." << std::endl;
                    EnrollMeDb.closeDB();
                    return 0;
                }
                EnrollMeDb.closeDB();
            }
            return 0;
        }
        else if (strcmp(argv[1], "seeddb") == 0)
        {
			// seed the database
			Database EnrollMeDb(dbPath);
            if (EnrollMeDb.openDB())
            {
                if (EnrollMeDb.seedDatabase())
                {
					std::cout << "EnrollMe database seeded successfully." << std::endl;
					EnrollMeDb.closeDB();
					return 0;
				}
				EnrollMeDb.closeDB();
			}
			return 0;
		}
        else if (strcmp(argv[1], "run") == 0)
        {
            // add the main app here later
            std::cout << "Running EnrollMe..." << std::endl;
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
            Logging log;

            home.include_routes(EnrollMeApp);
            enroll.include_routes(EnrollMeApp);
            log.include_routes(EnrollMeApp);


            //set the port, set the app to run on multiple threads, and run the app
            EnrollMeApp.bindaddr("127.0.0.1")
                .port(18080)
                .multithreaded()
                .run_async();
        }
    }
}