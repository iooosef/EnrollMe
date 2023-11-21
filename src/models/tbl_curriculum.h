#pragma once

struct tbl_curriculum {
	int id;
	std::string course_code;
	std::string course_title;
	int units;
	std::shared_ptr<std::string> prerequisite;
	std::shared_ptr<std::string> corequisite;
	std::shared_ptr<std::string> metadata;
};