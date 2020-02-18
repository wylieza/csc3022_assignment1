
#ifndef DATABASE_TOOLS_H //This is to ensure that the header not included twice by accident
#define DATABASE_TOOLS_H 


namespace WYLJUS002{

    struct student_record{
            std::string name;
            std::string surname;
            std::string student_no;
            std::string class_record;
        };

    //Define functions
    void add_student(); // void add_student(std::string name, std::string surname, std::string student_no, std::string, std::string class_record);
    void read_database();
    void save_database();
    void disp_student();
    void grade_student();

}

#endif