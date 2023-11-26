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
		// GET ROUTES
		void StuLvl(crow::App<crow::CookieParser, Session>& thisapp);
		void StuLvl_Elem(crow::App<crow::CookieParser, Session>& thisapp);
		void StuLvl_Jhs(crow::App<crow::CookieParser, Session>& thisapp);
		void StuLvl_Shs(crow::App<crow::CookieParser, Session>& thisapp);
		void StuLvl_College(crow::App<crow::CookieParser, Session>& thisapp);
		void StuType(crow::App<crow::CookieParser, Session>& thisapp);
		void StuType_NewStu(crow::App<crow::CookieParser, Session>& thisapp);
		void StuType_Freshmen(crow::App<crow::CookieParser, Session>& thisapp);
		void StuType_TranShft(crow::App<crow::CookieParser, Session>& thisapp);
		void StuType_OldStu(crow::App<crow::CookieParser, Session>& thisapp);

		void EnrollForm(crow::App<crow::CookieParser, Session>& thisapp);
		// POST ROUTES

		// MISC FUNCTIONS
		void ClearSession(crow::App<crow::CookieParser, Session>& thisapp, const crow::request& req);
};		