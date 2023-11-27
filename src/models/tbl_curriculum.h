#pragma once
#include <optional>

struct tbl_curriculum {
	int id;
	std::string course_code;
	std::string course_title;
	std::optional<int> lecture_units;
	std::optional<int> lab_units;
	std::optional<std::string> prerequisite;
	std::optional<std::string> corequisite;
	std::optional<std::string> metadata;
};