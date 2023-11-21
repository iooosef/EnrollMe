#pragma once

struct tbl_curriculum {
	int id;
	std::string course_code;
	std::string course_title;
	int units;
	std::optional<std::string> prerequisite;
	std::optional<std::string> corequisite;
	std::optional<std::string> metadata;
};