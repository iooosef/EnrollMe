## Transaction Sequence for College Enrollees

```mermaid
    flowchart TD
        start([START])
        start --> dclr1{{"`
                        tbl_enrollees
                        schoolYear = '2023-2024'
                        semester = 1
                        `"}}
        dclr1 --> flw1["`**INPUT** tbl_enrollees.enrll_type`"]
        flw1 --> if1{"`tbl_enrollees.enrll_type == 'oldStu'`"}
        if1 -- Yes --> flw2Y["`**INPUT** tbl_enrollees.student_number`"]
        if1 -- No --> flw3
        flw2Y --> flw3["`**INPUT** tbl_enrollees.enrll_level`"]
        flw3 --> if2{"`tbl_enrollees.enrll_level == 'SHS'`"}
        if2 -- Yes --> flw4Y["`**USE** shs_options **FOR** enrll_program`"]
        if2 -- No --> if3{"`tbl_enrollees.enrll_level == 'tertiary'`"}
        if3 -- Yes --> flw5Y["`**USE** tertiary_options **FOR** enrll_program`"]
        flw5Y --> flw6["`**INPUT** tbl_enrollees.enrll_program`"]
        flw6 --> if4{"`tbl_enrollees.enrll_type == 'oldStu'`"}
        if4 -- Yes --> flw7Y["`
                               **AS** @passed_classes
                               **GET ALL** course_code 
                               **IN** tbl_course_history 
                               **OF** tbl_enrollees.student_number
                               **WHERE**
                               tbl_course_history.remarks == 'passed'
                            `"]
        flw7Y --> flw8["`
                       **AS** @eligible_co-n-norequisite_classes
                       **GET ALL** course_code
                       **IN** tbl_curriculum
                       **OF** tbl_enrollees.enrll_program
                       **WHERE**
                       tbl_curriculum.prerequisite **IS BLANK**
                       **AND**
                       course_code **DOES NOT EXIST IN** @passed_classes
                     `"]
        flw8 --> flw9["`
                       **AS** @eligible_prerequisite_classes
                       **GET ALL** course_code
                       **IN** tbl_curriculum
                       **OF** tbl_enrollees.enrll_program
                       **WHERE**
                        tbl_curriculum.prerequisite **EXIST IN** @passed_classes
                       **AND**
                       course_code **DOES NOT EXIST IN** @passed_classes
                     `"]
        flw9 --> flw10["`
                        **AS** @eligible_classes
                        **MERGE**
                        @eligible_co-n-norequisite_classes
                        **AND**
                        @eligible_prerequisite_classes
                      `"]
        flw10 --> flw11["`
                        **USE** @eligible_classes option **FOR** enrll_program
                        `"]
        flw11 --> if5{"`enrll_program **HAS** corequisite **AND**  corequisite **EXIST IN** enrll_program`"}
        if5 -- No --> err1["`**THROW** err`"]
        err1 --> if5
        if5 -- Yes --> flw12["`tbl_enrollees.enrll_schoolYear = schoolYear`"]
        flw12 --> flw13["`tbl_enrollees.enrll_semester = semester`"]
        flw13 --> flw14["`
                        **INPUT** remaining
                        tbl_enrollees fields
                        `"]
        flw14 --> flw15["`**GENERATE** enrll_transactionId`"]
```
