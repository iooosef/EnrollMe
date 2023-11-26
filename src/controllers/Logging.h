#pragma once

#include <iostream>

#include <crow.h>
#include "../include/crow/middlewares/session.h"

using Session = crow::SessionMiddleware<crow::FileStore>;

class Logging
{
	public:
		Logging();
		void include_routes(crow::App<crow::CookieParser, Session>& thisapp);
	private:
		void LogSession(crow::App<crow::CookieParser, Session>& thisapp);
};