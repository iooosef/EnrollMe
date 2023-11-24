#pragma once

#include <iostream>

#include <crow.h>
#include "../include/crow/middlewares/session.h"

using Session = crow::SessionMiddleware<crow::FileStore>;

class Enroll
{
	public:
		Enroll();
		void include_routes(crow::App<crow::CookieParser, Session>& thisapp);
	private:
		void test(crow::App<crow::CookieParser, Session>& thisapp);
};