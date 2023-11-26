#include "Logging.h"

Logging::Logging()
{
	//ctor
}

void Logging::include_routes(crow::App<crow::CookieParser, Session>& thisapp)
{
    LogSession(thisapp);
}

void Logging::LogSession(crow::App<crow::CookieParser, Session>& thisapp)
{
    CROW_ROUTE(thisapp, "/log/session")(
        [&](const crow::request& req) {
            auto& session = thisapp.get_context<Session>(req);
            auto keys = session.keys();

            std::string existing_keys;
            for (const auto& key : keys)
            {
                existing_keys += "<p> " + key + " = " + session.string(key) + "</p>";
            }

            return existing_keys;
        });
}