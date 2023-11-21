#pragma once

struct tbl_college_class_enroll {
	int id;
	std::string enrll_transactionId;
	std::shared_ptr<int> student_number;
	std::string enrll_type;
	std::string enrll_program;
	std::string enrll_schoolYear;
	int enrll_semester;
	std::string course_code;
};