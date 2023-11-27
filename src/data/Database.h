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
		bool seedTblCurriculum();
	private:
		const char* dbName_;
		sqlite3* db_;
};