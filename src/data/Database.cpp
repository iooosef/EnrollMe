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

void Database::errHandling(int returnCode) {
	std::cerr << "SQLite error: " << sqlite3_errstr(returnCode) << std::endl;
	std::cerr << "SQLite error message: " << sqlite3_errmsg(db_) << std::endl;
}

bool Database::initEnrollMeTables()
{
	const std::string create_tbl_enrollees = "CREATE TABLE IF NOT EXISTS tbl_enrollees ("
											 "id INTEGER PRIMARY KEY AUTOINCREMENT,"
											 "student_number TEXT,"
											 "enrll_transactionId TEXT NOT NULL UNIQUE,"
											 "enrll_type TEXT NOT NULL,"
											 "enrll_level TEXT NOT NULL,"
											 "enrll_program TEXT,"
											 "enrll_schoolYear TEXT NOT NULL,"
											 "enrll_semester TEXT NOT NULL,"
											 "enrll_firstName TEXT NOT NULL,"
											 "enrll_midName TEXT,"
											 "enrll_lastName TEXT NOT NULL,"
											 "enrll_suffixName TEXT,"
											 "enrll_sex TEXT NOT NULL,"
											 "enrll_DoB TEXT NOT NULL,"
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
											 "grdn_address TEXT NOT NULL,"
											 "grdn_mobileNumber TEXT NOT NULL,"
											 "grdn_telephoneNumber TEXT,"
											 "grdn_email TEXT NOT NULL"
											 ")";

	const std::string create_tbl_studentNfo = "CREATE TABLE IF NOT EXISTS tbl_studentNfo ("
											  "student_number TEXT PRIMARY KEY,"
											  "enrll_firstName TEXT NOT NULL,"
											  "enrll_midName TEXT,"
										  	  "enrll_lastName TEXT NOT NULL,"
											  "enrll_suffixName TEXT,"
											  "enrll_sex TEXT NOT NULL,"
											  "enrll_DoB TEXT NOT NULL,"
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
											  "grdn_address TEXT NOT NULL,"
											  "grdn_mobileNumber TEXT NOT NULL,"
											  "grdn_telephoneNumber TEXT,"
											  "grdn_email TEXT NOT NULL"
											  ")";

	const std::string create_tbl_curriculum = "CREATE TABLE IF NOT EXISTS tbl_curriculum ("
											  "id INTEGER PRIMARY KEY AUTOINCREMENT,"
											  "curriculum TEXT NOT NULL,"
											  "course_code TEXT NOT NULL,"
											  "course_title TEXT NOT NULL,"
											  "lecture_units TEXT,"
											  "lab_units TEXT,"
											  "prerequisite TEXT,"
											  "corequisite TEXT,"
											  "metadata TEXT"
											  ")";

	const std::string create_tbl_college_class_enroll = "CREATE TABLE IF NOT EXISTS tbl_college_class_enroll ("
													    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
													    "enrll_transactionId TEXT NOT NULL,"
													    "student_number TEXT,"
													    "enrll_program TEXT NOT NULL,"
													    "enrll_schoolYear TEXT NOT NULL,"
													    "enrll_type TEXT NOT NULL,"
													    "enrll_semester TEXT NOT NULL,"
													    "course_code TEXT NOT NULL"
													    ")";

	const std::string create_tbl_course_history = "CREATE TABLE IF NOT EXISTS tbl_course_history ("
												  "id INTEGER PRIMARY KEY AUTOINCREMENT,"
												  "student_number TEXT,"
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

bool Database::loadCurriculum()
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

bool Database::seedDatabase()
{
	std::vector<std::string> studentNfo_columns = { "student_number", "enrll_firstName", "enrll_midName", "enrll_lastName", "enrll_suffixName",
												    "enrll_sex", "enrll_DoB", "enrll_PoB", "enrll_religion", "enrll_nationality", "enrll_civilStatus",
											   	    "enrll_country", "enrll_province", "enrll_cityMun", "enrll_brgy", "enrll_zipCode", "enrll_addrLine",
												    "enrll_mobileNumber", "enrll_telephoneNumber", "enrll_email",
												    "grdn_firstName", "grdn_midName", "grdn_lastName", "grdn_suffixName", "grdn_sex", "grdn_relation",
												    "grdn_address", "grdn_mobileNumber", "grdn_telephoneNumber", "grdn_email" };
	std::vector<std::string> studentNfo_values[2] = { {
														"2002406", "Joseph", "Cabacungan", "Parayaoan", "", "Male", "2001-07-22", "Quezon City", 
														"Roman Catholic", "Filipino", "Single", "PHL", "Rizal", "Cainta", "San Juan", "1900", 
														"16 7th St. Youngstown Village", "09613697364", "", "josence22@gmail.com", 
														"Rosemarie", "Cabacungan", "Parayaoan", "", "Female", "Mother",
														"16 7th St. Youngstown Village, San Juan, Cainta, Rizal", "09186050846", "", "rosepccc@gmail.com"
													  },
													  {
														"2106499", "Clarence", "B", "Danilo", "", "Male", "2002-06-01", "Quezon City", 
														"Roman Catholic", "Filipino", "Single", "PHL", "Rizal", "Antipolo", "Sto Nino", "",
														"Blk 2 Lot 3, St. Jude St. St. Nino Village", "09123456789", "", "",
														"Ernesto", "Miranda", "Danilo", "", "Male", "Father",
														"Blk 2 Lot 3, St. Jude St. St. Nino Village, Antipolo, Rizal", "09123456789", "", "edanilo@yahoo.com"
													  }
													};
	std::vector<std::string> courseHistory_columns = { "student_number", "course_code", "remarks" };
	std::vector<std::string> courseHistory_values[8] = { {"2002406", "GEC004", "PASSED"}, {"2002406", "GEC001", "PASSED"}, {"2002406", "MATH013", "PASSED"},
															{"2002406", "MATH014", "PASSED"}, {"2002406", "CS001", "PASSED"}, {"2002406", "ITE001", "PASSED"},
															{"2002406", "PE001", "PASSED"}, {"2002406", "NSTP001", "PASSED"}
														};

	for (int i = 0; i < 2; i++)
	{
		if (!executeInsert("tbl_studentNfo", studentNfo_columns, studentNfo_values[i]))
		{
			std::cout << "Error inserting values for tbl_studentNfo" << std::endl;
			return false;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		if (!executeInsert("tbl_course_history", courseHistory_columns, courseHistory_values[i]))
		{
			std::cout << "Error inserting values for tbl_course_history" << std::endl;
			return false;
		}
	}

	return true;
}

bool Database::executeInsert(const std::string& table, const std::vector<std::string>& columns, const std::vector<std::string>& values)
{
	if (db_ == nullptr || columns.empty() || values.empty() || columns.size() != values.size()) {
		return false;
	}
	std::string query = "INSERT INTO " + table + " (";
	for (size_t i = 0; i < columns.size(); ++i) {
		query += columns[i];
		if (i < columns.size() - 1) {
			query += ",";
		}
	}
	query += ") VALUES (";
	for (size_t i = 0; i < values.size(); ++i) {
		query += "'" + values[i] + "'";
		if (i < values.size() - 1) {
			query += ",";
		}
	}
	query += ");";

	std::cout << std::endl << query << std::endl;

	int result = sqlite3_exec(db_, query.c_str(), nullptr, nullptr, nullptr);
	return (result == SQLITE_OK);
}

std::vector<std::vector<std::string>> Database::executeSelect(const std::string& query)
{
	std::vector<std::vector<std::string>> result;

	if (db_ == nullptr) {
		std::cerr << "Database not open." << std::endl;
		return result;
	}

	sqlite3_stmt* statement;
	if (sqlite3_prepare_v2(db_, query.c_str(), -1, &statement, nullptr) != SQLITE_OK) {
		std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db_) << std::endl;
		return result;
	}

	int columns = sqlite3_column_count(statement);

	while (sqlite3_step(statement) == SQLITE_ROW) {
		std::vector<std::string> row;

		for (int i = 0; i < columns; ++i) {
			const char* value = reinterpret_cast<const char*>(sqlite3_column_text(statement, i));
			row.push_back(value ? value : "");
		}

		result.push_back(row);
	}

	sqlite3_finalize(statement);
	return result;
}