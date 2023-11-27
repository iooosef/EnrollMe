#pragma once
#include <optional>

struct tbl_studentNfo {
	std::optional<int> student_number;
	std::string student_firstName;
	std::optional<std::string> student_midName;
	std::string student_lastName;
	std::optional<std::string> student_suffixName;
	std::string student_sex;
	std::string student_DoB;
	std::optional<std::string> student_PoB;
	std::string student_religion;
	std::string student_nationality;
	std::string student_civilStatus;
	std::string student_country;
	std::string student_province;
	std::string student_cityMun;
	std::string student_brgy;
	std::optional<std::string> student_zipCode;
	std::string student_addrLine;
	std::optional<std::string> student_mobileNumber;
	std::optional<std::string> student_telephoneNumber;
	std::optional<std::string> student_email;
	std::string grdn_firstName;
	std::string grdn_midName;
	std::string grdn_lastName;
	std::optional<std::string> grdn_suffixName;
	std::string grdn_sex;
	std::string grdn_relation;
	std::string grn_address;
	std::string grn_mobileNumber;
	std::optional<std::string> grn_telephoneNumber;
	std::optional<std::string> grn_email;
};