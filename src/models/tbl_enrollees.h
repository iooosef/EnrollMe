#pragma once
#include <optional>

struct tbl_enrollees {
	int id;
	std::optional<int> student_number;
	std::string enrll_transactionId;
	std::string enrll_type;
	std::string enrll_level;
	std::string enrll_program;
	std::string enrll_schoolYear;
	int enrll_semester;
	std::string enrll_firstName;
	std::optional<std::string> enrll_midName;
	std::string enrll_lastName;
	std::optional<std::string> enrll_suffixName;
	std::string enrll_sex;
	std::string enrll_DoB;
	std::optional<std::string> enrll_PoB;
	std::string enrll_religion;
	std::string enrll_nationality;
	std::string enrll_civilStatus;
	std::string enrll_country;
	std::string enrll_province;
	std::string enrll_cityMun;
	std::string enrll_brgy;
	std::optional<std::string> enrll_zipCode;
	std::string enrll_addrLine;
	std::optional<std::string> enrll_mobileNumber;
	std::optional<std::string> enrll_telephoneNumber;
	std::optional<std::string> enrll_email;
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