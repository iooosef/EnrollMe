## EnrollMe SQL Database Tables

### `tbl_enrollees`

|      type       |         name          | nullable |     key      |    misc     |
| :-------------: | :-------------------: | :------: | :----------: | :---------: |
|      *int*      |          id           |          |   ***PK***   | *INCREMENT* |
|      *int*      |    student_number     |    ✔     |              |             |
|     *text*      |  enrll_transactionId  |          | ***UNIQUE*** |             |
| *nvarchar(12)*  |      enrll_type       |          |              |             |
| *nvarchar(16)*  |      enrll_level      |          |              |             |
| *nvarchar(16)*  |     enrll_program     |          |              |             |
| *nvarchar(10)*  |   enrll_schoolYear    |          |              |             |
|      *int*      |    enrll_semester     |          |              |             |
|     *text*      |    enrll_firstName    |          |              |             |
|     *text*      |     enrll_midName     |    ✔     |              |             |
|     *text*      |    enrll_lastName     |          |              |             |
|     *text*      |   enrll_suffixName    |    ✔     |              |             |
|  *nvarchar(8)*  |       enrll_sex       |          |              |             |
|     *date*      |       enrll_DoB       |          |              |             |
|     *text*      |       enrll_PoB       |    ✔     |              |             |
|     *text*      |    enrll_religion     |          |              |             |
|  *nvarchar(3)*  |   enrll_nationality   |          |              |             |
| *nvarchar(12)*  |   enrll_civilStatus   |          |              |             |
|     *text*      |     enrll_country     |          |              |             |
|     *text*      |    enrll_province     |          |              |             |
|     *text*      |     enrll_cityMun     |          |              |             |
|     *text*      |      enrll_brgy       |          |              |             |
|  *nvarchar(5)*  |     enrll_zipCode     |    ✔     |              |             |
|     *text*      |    enrll_addrLine     |          |              |             |
| *nvarchar(16)*  |  enrll_mobileNumber   |    ✔     |              |             |
| *nvarchar(16)*  | enrll_telephoneNumber |    ✔     |              |             |
| *nvarchar(320)* |      enrll_email      |    ✔     |              |             |
|     *text*      |    grdn_firstName     |          |              |             |
|     *text*      |     grdn_midName      |    ✔     |              |             |
|     *text*      |     grdn_lastName     |          |              |             |
|     *text*      |    grdn_suffixName    |    ✔     |              |             |
|  *nvarchar(8)*  |       grdn_sex        |          |              |             |
| *nvarchar(32)*  |     grdn_relation     |          |              |             |
|     *text*      |      grn_address      |          |              |             |
| *nvarchar(16)*  |   grn_mobileNumber    |          |              |             |
| *nvarchar(16)*  |  grn_telephoneNumber  |    ✔     |              |             |
| *nvarchar(320)* |       grn_email       |          |              |             |

### `tbl_college_class_enroll`

|      type      |        name         | nullable |     key      |    misc     |
| :------------: | :-----------------: | :------: | :----------: | :---------: |
|     *int*      |         id          |          |   ***PK***   | *INCREMENT* |
|     *text*     | enrll_transactionId |          | ***UNIQUE*** |             |
|     *int*      |   student_number    |    ✔     |              |             |
| *nvarchar(16)* |    enrll_program    |          |              |             |
| *nvarchar(10)* |  enrll_schoolYear   |          |              |             |
|     *text*     | enrll_transactionId |          | ***UNIQUE*** |             |
| *nvarchar(12)* |     enrll_type      |          |              |             |
|     *int*      |   enrll_semester    |          |              |             |
| *nvarchar(12)* |     course_code     |          |              |             |

### `tbl_studentNfo`

|      type       |         name          | nullable |   key    | misc  |
| :-------------: | :-------------------: | :------: | :------: | :---: |
|      *int*      |    student_number     |          | ***PK*** |       |
|     *text*      |    enrll_firstName    |          |          |       |
|     *text*      |     enrll_midName     |    ✔     |          |       |
|     *text*      |    enrll_lastName     |          |          |       |
|     *text*      |   enrll_suffixName    |    ✔     |          |       |
|  *nvarchar(8)*  |       enrll_sex       |          |          |       |
|     *date*      |       enrll_DoB       |          |          |       |
|     *text*      |       enrll_PoB       |    ✔     |          |       |
|     *text*      |    enrll_religion     |          |          |       |
|  *nvarchar(3)*  |   enrll_nationality   |          |          |       |
| *nvarchar(12)*  |   enrll_civilStatus   |          |          |       |
|     *text*      |     enrll_country     |          |          |       |
|     *text*      |    enrll_province     |          |          |       |
|     *text*      |     enrll_cityMun     |          |          |       |
|     *text*      |      enrll_brgy       |          |          |       |
|  *nvarchar(5)*  |     enrll_zipCode     |    ✔     |          |       |
|     *text*      |    enrll_addrLine     |          |          |       |
| *nvarchar(16)*  |  enrll_mobileNumber   |    ✔     |          |       |
| *nvarchar(16)*  | enrll_telephoneNumber |    ✔     |          |       |
| *nvarchar(320)* |      enrll_email      |    ✔     |          |       |
|     *text*      |    grdn_firstName     |          |          |       |
|     *text*      |     grdn_midName      |    ✔     |          |       |
|     *text*      |     grdn_lastName     |          |          |       |
|     *text*      |    grdn_suffixName    |    ✔     |          |       |
|  *nvarchar(8)*  |       grdn_sex        |          |          |       |
| *nvarchar(32)*  |     grdn_relation     |          |          |       |
|     *text*      |      grn_address      |          |          |       |
| *nvarchar(16)*  |   grn_mobileNumber    |          |          |       |
| *nvarchar(16)*  |  grn_telephoneNumber  |    ✔     |          |       |
| *nvarchar(320)* |       grn_email       |          |          |       |

### `tbl_curriculum`

|      type      |     name     | nullable |   key    |    misc     |
| :------------: | :----------: | :------: | :------: | :---------: |
|     *int*      |      id      |          | ***PK*** | *INCREMENT* |
| *nvarchar(12)* | course_code  |          |          |             |
|      text      | course_title |          |          |             |
|      int       |    units     |          |          |             |
| *nvarchar(12)* | prerequisite |    ✔     |          |             |
| *nvarchar(12)* | corequisite  |    ✔     |          |             |
|      text      |   metadata   |    ✔     |          |             |

### `tbl_course_history`

|      type      |      name      | nullable |   key    |    misc     |    REFERENCES    |
| :------------: | :------------: | :------: | :------: | :---------: | :--------------: |
|     *int*      |       id       |          | ***PK*** | *INCREMENT* |                  |
|     *int*      | student_number |          | ***FK*** |             | tbl_enrollees.id |
| *nvarchar(12)* |  course_code   |          |          |             |                  |
| *nvarchar(12)* |    remarks     |          |          |             |                  |

---
## Form Options

#### `tbl_enrollees.enrll_type` options
| value  |    text     |
| :----: | :---------: |
| newStu | New Student |
| oldStu | Old Student |

#### `tbl_enrollees.enrll_level` options
|  value   |        text        |
| :------: | :----------------: |
| primary  |   Primary School   |
|   JHS    | Junior High School |
|   SHS    | Senior High School |
| tertiary |      College       |

#### `tbl_enrollees.enrll_program` options WHERE `enrll_level` = `shs`
| value |                      text                      |
| :---: | :--------------------------------------------: |
| STEM  | Science, Technology, Engineering & Mathematics |
|  ABM  |       Accountancy, Business & Management       |
| HUMMS |          Humanities & Social Sciences          |
|  GAS  |            General Academic Strand             |

#### `tbl_enrollees.enrll_program` options WHERE `enrll_level` = `tertiary`
| value |                    text                     |
| :---: | :-----------------------------------------: |
| BSCS  |   Bachelor of Science in Computer Science   |
| BSCPE | Bachelor of Science in Computer Engineering |
