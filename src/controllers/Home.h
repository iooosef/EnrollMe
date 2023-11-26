#pragma once

#include <iostream>

#include <crow.h>
#include "../include/crow/middlewares/session.h"

using Session = crow::SessionMiddleware<crow::FileStore>;

class Home
{
	public:
		Home();
		void include_routes(crow::App<crow::CookieParser, Session>& thisapp);
	private:
		void index(crow::App<crow::CookieParser, Session>& thisapp);
		// MISC FUNCTIONS
		void ClearSession(crow::App<crow::CookieParser, Session>& thisapp, const crow::request& req);
};