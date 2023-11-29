#pragma once

#include <iostream>

#include <crow.h>
#include "../include/crow/middlewares/session.h"
#include "data/Database.h"

using Session = crow::SessionMiddleware<crow::FileStore>;

class Enroll
{
	public:
		Enroll();
		void include_routes(crow::App<crow::CookieParser, Session>& thisapp);
	private:
		// GET ROUTES
		void StuLvl(crow::App<crow::CookieParser, Session>& thisapp);
		void StuLvl_Elem(crow::App<crow::CookieParser, Session>& thisapp);
		void StuLvl_Jhs(crow::App<crow::CookieParser, Session>& thisapp);
		void StuLvl_Shs(crow::App<crow::CookieParser, Session>& thisapp);
		void StuLvl_College(crow::App<crow::CookieParser, Session>& thisapp);
		void StuType(crow::App<crow::CookieParser, Session>& thisapp);
		void StuType_NewStu(crow::App<crow::CookieParser, Session>& thisapp);
		void StuType_Freshmen(crow::App<crow::CookieParser, Session>& thisapp);
		void StuType_Transferee(crow::App<crow::CookieParser, Session>& thisapp);
		void StuType_Shiftee(crow::App<crow::CookieParser, Session>& thisapp);
		void StuType_OldStu(crow::App<crow::CookieParser, Session>& thisapp);

		void EnrollForm(crow::App<crow::CookieParser, Session>& thisapp);
		void EnrollFormPOST(crow::App<crow::CookieParser, Session>& thisapp);
		// POST ROUTES

		// HTMX ROUTES
		void testHTMX(crow::App<crow::CookieParser, Session>& thisapp);
		void getNationalities(crow::App<crow::CookieParser, Session>& thisapp);
		void getCountries(crow::App<crow::CookieParser, Session>& thisapp);

		// MISC FUNCTIONS
		void ClearSession(crow::App<crow::CookieParser, Session>& thisapp, const crow::request& req);
		std::string generateShortUUID();
};		