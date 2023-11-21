#pragma once

struct tbl_curriculum {
	int id;
	std::string course_code;
	std::string course_title;
	int units;
	std::string prerequisite;
	std::string corequisite;
	std::string metadata;
};