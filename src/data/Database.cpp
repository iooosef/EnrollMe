#include "Database.h"

// ctor
Database::Database(const char* dbPath) :  dbName_(dbPath), db_(nullptr) { }
// dtor
Database::~Database() 
{
	if (db_)
	{
		sqlite3_close(db_);
	}
}

bool Database::openDB()
{
	int returnCode = sqlite3_open(dbName_, &db_);
	if (returnCode != SQLITE_OK)
	{
		std::cout << "Error opening database: " << sqlite3_errmsg(db_) << std::endl;
		return false;
	}
	return true;
}

bool Database::closeDB()
{
	int returnCode = sqlite3_close(db_);
	if (returnCode != SQLITE_OK)
	{
		std::cout << "Error closing database: " << sqlite3_errmsg(db_) << std::endl;
		return false;
	}
	return true;
}

bool Database::initEnrollMeTables()
{
	const std::string create_tbl_enrollees = "CREATE TABLE IF NOT EXISTS tbl_enrollees ("
											 "id INTEGER PRIMARY KEY AUTOINCREMENT,"
											 "student_number INTEGER,"
											 "enrll_transactionId TEXT NOT NULL UNIQUE,"
											 "enrll_type TEXT NOT NULL,"
											 "enrll_level TEXT NOT NULL,"
											 "enrll_program TEXT NOT NULL,"
											 "enrll_schoolYear TEXT NOT NULL,"
											 "enrll_semester INTEGER NOT NULL,"
											 "enrll_firstName TEXT NOT NULL,"
											 "enrll_midName TEXT,"
											 "enrll_lastName TEXT NOT NULL,"
											 "enrll_suffixName TEXT,"
											 "enrll_sex TEXT NOT NULL,"
											 "enrll_DoB INTEGER NOT NULL,"
											 "enrll_PoB TEXT,"
											 "enrll_religion TEXT NOT NULL,"
											 "enrll_nationality TEXT NOT NULL,"
											 "enrll_civilStatus TEXT NOT NULL,"
											 "enrll_country TEXT NOT NULL,"
											 "enrll_province TEXT NOT NULL,"
											 "enrll_cityMun TEXT NOT NULL,"
											 "enrll_brgy TEXT NOT NULL,"
											 "enrll_zipCode TEXT,"
											 "enrll_addrLine TEXT NOT NULL,"
											 "enrll_mobileNumber TEXT,"
											 "enrll_telephoneNumber TEXT,"
											 "enrll_email TEXT,"
											 "grdn_firstName TEXT NOT NULL,"
											 "grdn_midName TEXT,"
											 "grdn_lastName TEXT NOT NULL,"
											 "grdn_suffixName TEXT,"
											 "grdn_sex TEXT NOT NULL,"
											 "grdn_relation TEXT NOT NULL,"
											 "grn_address TEXT NOT NULL,"
											 "grn_mobileNumber TEXT NOT NULL,"
											 "grn_telephoneNumber TEXT,"
											 "grn_email TEXT NOT NULL"
											 ")";

	const std::string create_tbl_studentNfo = "CREATE TABLE IF NOT EXISTS tbl_studentNfo ("
											  "student_number INTEGER PRIMARY KEY,"
											  "enrll_firstName TEXT NOT NULL,"
											  "enrll_midName TEXT,"
										  	  "enrll_lastName TEXT NOT NULL,"
											  "enrll_suffixName TEXT,"
											  "enrll_sex TEXT NOT NULL,"
											  "enrll_DoB INTEGER NOT NULL,"
											  "enrll_PoB TEXT,"
											  "enrll_religion TEXT NOT NULL,"
											  "enrll_nationality TEXT NOT NULL,"
											  "enrll_civilStatus TEXT NOT NULL,"
											  "enrll_country TEXT NOT NULL,"
											  "enrll_province TEXT NOT NULL,"
											  "enrll_cityMun TEXT NOT NULL,"
											  "enrll_brgy TEXT NOT NULL,"
											  "enrll_zipCode TEXT,"
											  "enrll_addrLine TEXT NOT NULL,"
											  "enrll_mobileNumber TEXT,"
											  "enrll_telephoneNumber TEXT,"
											  "enrll_email TEXT,"
											  "grdn_firstName TEXT NOT NULL,"
											  "grdn_midName TEXT,"
											  "grdn_lastName TEXT NOT NULL,"
											  "grdn_suffixName TEXT,"
											  "grdn_sex TEXT NOT NULL,"
											  "grdn_relation TEXT NOT NULL,"
											  "grn_address TEXT NOT NULL,"
											  "grn_mobileNumber TEXT NOT NULL,"
											  "grn_telephoneNumber TEXT,"
											  "grn_email TEXT NOT NULL"
											  ")";

	const std::string create_tbl_curriculum = "CREATE TABLE IF NOT EXISTS tbl_curriculum ("
											  "id INTEGER PRIMARY KEY AUTOINCREMENT,"
											  "curriculum TEXT NOT NULL,"
											  "course_code TEXT NOT NULL,"
											  "course_title TEXT NOT NULL,"
											  "lecture_units INTEGER,"
											  "lab_units INTEGER,"
											  "prerequisite TEXT,"
											  "corequisite TEXT,"
											  "metadata TEXT"
											  ")";

	const std::string create_tbl_college_class_enroll = "CREATE TABLE IF NOT EXISTS tbl_college_class_enroll ("
													    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
													    "enrll_transactionId TEXT NOT NULL,"
													    "student_number INTEGER,"
													    "enrll_program TEXT NOT NULL,"
													    "enrll_schoolYear TEXT NOT NULL,"
													    "enrll_type TEXT NOT NULL,"
													    "enrll_semester INTEGER NOT NULL,"
													    "course_code TEXT NOT NULL"
													    ")";

	const std::string create_tbl_course_history = "CREATE TABLE IF NOT EXISTS tbl_course_history ("
												  "id INTEGER PRIMARY KEY AUTOINCREMENT,"
												  "student_number INTEGER,"
												  "course_code TEXT NOT NULL,"
												  "remarks TEXT NOT NULL"
												  ")";
	
	int returnCode = sqlite3_exec(db_, create_tbl_enrollees.c_str(), NULL, NULL, NULL);
	if (returnCode != SQLITE_OK)
	{
		std::cout << "Error creating table tbl_enrollees: " << sqlite3_errmsg(db_) << std::endl;
		return false;
	}

	returnCode = sqlite3_exec(db_, create_tbl_studentNfo.c_str(), NULL, NULL, NULL);
	if (returnCode != SQLITE_OK)
	{
		std::cout << "Error creating table tbl_studentNfo: " << sqlite3_errmsg(db_) << std::endl;
		return false;
	}

	returnCode = sqlite3_exec(db_, create_tbl_curriculum.c_str(), NULL, NULL, NULL);
	if (returnCode != SQLITE_OK)
	{
		std::cout << "Error creating table tbl_curriculum: " << sqlite3_errmsg(db_) << std::endl;
		return false;
	}

	returnCode = sqlite3_exec(db_, create_tbl_college_class_enroll.c_str(), NULL, NULL, NULL);
	if (returnCode != SQLITE_OK)
	{
		std::cout << "Error creating table tbl_college_class_enroll: " << sqlite3_errmsg(db_) << std::endl;
		return false;
	}

	returnCode = sqlite3_exec(db_, create_tbl_course_history.c_str(), NULL, NULL, NULL);
	if (returnCode != SQLITE_OK)
	{
		std::cout << "Error creating table tbl_course_history: " << sqlite3_errmsg(db_) << std::endl;
		return false;
	}
	
	return true;
}

bool Database::seedTblCurriculum()
{
	{
		// reset tbl_curriculum
		std::string resetQuery = "DELETE FROM tbl_curriculum";
		int returnCode = sqlite3_exec(db_, resetQuery.c_str(), NULL, NULL, NULL);
		if (returnCode != SQLITE_OK)
		{
			std::cout << "Error resetting table tbl_curriculum: " << sqlite3_errmsg(db_) << std::endl;
			return false;
		}
	}

	// insert data into tbl_curriculum
	std::ifstream file("./data/tbl_curriculum.csv");
	if (!file.is_open())
	{
		std::cout << "Error opening file tbl_curriculum.csv" << std::endl;
		return false;
	}

	std::string line;

	while (std::getline(file, line)) // read line by line
	{
		std::istringstream iss(line);
		std::string value;

		std::vector<std::string> values;

		while (std::getline(iss, value, '$'))
		{
			values.push_back(value);
		}

		std::string seedQuery = "INSERT INTO tbl_curriculum ("
							    "curriculum, course_code, course_title, lecture_units, lab_units,"
							    "prerequisite, corequisite, metadata )"
								"VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
		sqlite3_stmt* stmt;

		if (sqlite3_prepare_v2(db_, seedQuery.c_str(), -1, &stmt, NULL) != SQLITE_OK)
		{
			std::cout << "Error preparing statement: " << sqlite3_errmsg(db_) << std::endl;
			return false;
		}

		for (int i = 0; i < 8; i++)
		{
			if (sqlite3_bind_text(stmt, i + 1, values[i].c_str(), -1, SQLITE_STATIC) != SQLITE_OK)
			{
				std::cout << "Error binding value: " << sqlite3_errmsg(db_) << std::endl;
				return false;
			}
		}
		std::cout << "Added values for " << values[0] << " - " << values[1] << std::endl;

		// Execute the statement
		if (sqlite3_step(stmt) != SQLITE_DONE) {
			std::cerr << "Error executing statement." << std::endl;
			return false;
		}

		// Finalize the statement
		if (sqlite3_finalize(stmt) != SQLITE_OK) {
			std::cerr << "Cannot finalize statement." << std::endl;
			return false;
		}

		std::cout << std::endl;
	}

	file.close();
	return true;
}