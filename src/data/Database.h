#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <sqlite3.h>

// DB models
#include "models/tbl_enrollees.h"
#include "models/tbl_studentNfo.h"
#include "models/tbl_curriculum.h"
#include "models/tbl_college_class_enroll.h"
#include "models/tbl_course_history.h"

class Database
{
	public:
		Database(const char* dbPath);
		~Database();
		bool openDB();
		bool closeDB();

		bool initEnrollMeTables();
		bool loadCurriculum();
		bool seedDatabase();

		bool executeInsert(const std::string& table, const std::vector<std::string>& columns, const std::vector<std::string>& values);
		std::vector<std::vector<std::string>> executeSelect(const std::string& query);
	private:
		const char* dbName_;
		sqlite3* db_;

		void errHandling(int returnCode);
};