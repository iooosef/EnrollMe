#pragma once

#include <iostream>

#include <crow.h>

class Home
{
	public:
		Home();
		void include_routes(crow::SimpleApp& thisapp);
	private:
		void index(crow::SimpleApp& thisapp);
};