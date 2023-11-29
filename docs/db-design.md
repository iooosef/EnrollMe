## EnrollMe SQL Database Tables

### `tbl_enrollees`

|  type  |         name          | nullable |     key      |    misc     |
| :----: | :-------------------: | :------: | :----------: | :---------: |
| *int*  |          id           |          |   ***PK***   | *INCREMENT* |
| *int*  |    student_number     |    ✔     |              |             |
| *text* |  enrll_transactionId  |          | ***UNIQUE*** |             |
| *text* |      enrll_type       |          |              |             |
| *text* |      enrll_level      |          |              |             |
| *text* |     enrll_program     |          |              |             |
| *text* |   enrll_schoolYear    |          |              |             |
| *text* |    enrll_semester     |          |              |             |
| *text* |    enrll_firstName    |          |              |             |
| *text* |     enrll_midName     |    ✔     |              |             |
| *text* |    enrll_lastName     |          |              |             |
| *text* |   enrll_suffixName    |    ✔     |              |             |
| *text* |       enrll_sex       |          |              |             |
| *text* |       enrll_DoB       |          |              |             |
| *text* |       enrll_PoB       |    ✔     |              |             |
| *text* |    enrll_religion     |          |              |             |
| *text* |   enrll_nationality   |          |              |             |
| *text* |   enrll_civilStatus   |          |              |             |
| *text* |     enrll_country     |          |              |             |
| *text* |    enrll_province     |          |              |             |
| *text* |     enrll_cityMun     |          |              |             |
| *text* |      enrll_brgy       |          |              |             |
| *text* |     enrll_zipCode     |    ✔     |              |             |
| *text* |    enrll_addrLine     |          |              |             |
| *text* |  enrll_mobileNumber   |    ✔     |              |             |
| *text* | enrll_telephoneNumber |    ✔     |              |             |
| *text* |      enrll_email      |    ✔     |              |             |
| *text* |    grdn_firstName     |          |              |             |
| *text* |     grdn_midName      |    ✔     |              |             |
| *text* |     grdn_lastName     |          |              |             |
| *text* |    grdn_suffixName    |    ✔     |              |             |
| *text* |       grdn_sex        |          |              |             |
| *text* |     grdn_relation     |          |              |             |
| *text* |      grn_address      |          |              |             |
| *text* |   grn_mobileNumber    |          |              |             |
| *text* |  grn_telephoneNumber  |    ✔     |              |             |
| *text* |       grn_email       |          |              |             |

### `tbl_college_class_enroll`

|  type  |        name         | nullable |   key    |    misc     |
| :----: | :-----------------: | :------: | :------: | :---------: |
| *int*  |         id          |          | ***PK*** | *INCREMENT* |
| *text* | enrll_transactionId |          |          |             |
| *text* |   student_number    |    ✔     |          |             |
| *text* |    enrll_program    |          |          |             |
| *text* |  enrll_schoolYear   |          |          |             |
| *text* |     enrll_type      |          |          |             |
| *text* |   enrll_semester    |          |          |             |
| *text* |     course_code     |          |          |             |

### `tbl_studentNfo`

|  type  |          name           | nullable |   key    | misc  |
| :----: | :---------------------: | :------: | :------: | :---: |
| *int*  |     student_number      |          | ***PK*** |       |
| *text* |    student_firstName    |          |          |       |
| *text* |     student_midName     |    ✔     |          |       |
| *text* |    student_lastName     |          |          |       |
| *text* |   student_suffixName    |    ✔     |          |       |
| *text* |       student_sex       |          |          |       |
| *text* |       student_DoB       |          |          |       |
| *text* |       student_PoB       |    ✔     |          |       |
| *text* |    student_religion     |          |          |       |
| *text* |   student_nationality   |          |          |       |
| *text* |   student_civilStatus   |          |          |       |
| *text* |     student_country     |          |          |       |
| *text* |    student_province     |          |          |       |
| *text* |     student_cityMun     |          |          |       |
| *text* |      student_brgy       |          |          |       |
| *text* |     student_zipCode     |    ✔     |          |       |
| *text* |    student_addrLine     |          |          |       |
| *text* |  student_mobileNumber   |    ✔     |          |       |
| *text* | student_telephoneNumber |    ✔     |          |       |
| *text* |      student_email      |    ✔     |          |       |
| *text* |     grdn_firstName      |          |          |       |
| *text* |      grdn_midName       |    ✔     |          |       |
| *text* |      grdn_lastName      |          |          |       |
| *text* |     grdn_suffixName     |    ✔     |          |       |
| *text* |        grdn_sex         |          |          |       |
| *text* |      grdn_relation      |          |          |       |
| *text* |       grn_address       |          |          |       |
| *text* |    grn_mobileNumber     |          |          |       |
| *text* |   grn_telephoneNumber   |    ✔     |          |       |
| *text* |        grn_email        |          |          |       |

### `tbl_curriculum`

|  type  |     name     | nullable |   key    |    misc     |
| :----: | :----------: | :------: | :------: | :---------: |
| *int*  |      id      |          | ***PK*** | *INCREMENT* |
| *text* | course_code  |          |          |             |
| *text* | course_title |          |          |             |
| *text* |    units     |          |          |             |
| *text* | prerequisite |    ✔     |          |             |
| *text* | corequisite  |    ✔     |          |             |
| *text* |   metadata   |    ✔     |          |             |

### `tbl_course_history`

|  type  |      name      | nullable |   key    |    misc     |
| :----: | :------------: | :------: | :------: | :---------: |
| *int*  |       id       |          | ***PK*** | *INCREMENT* |
| *text* | student_number |          |          |             |
| *text* |  course_code   |          |          |             |
| *text* |    remarks     |          |          |             |