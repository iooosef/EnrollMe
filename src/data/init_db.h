#pragma once

#include <iostream>

#include <sqlite_orm/sqlite_orm.h>

// DB models
#include "models/tbl_enrollees.h"
#include "models/tbl_studentNfo.h"
#include "models/tbl_curriculum.h"
#include "models/tbl_college_class_enroll.h"
#include "models/tbl_course_history.h"

void initDb();