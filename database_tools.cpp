
#include <iostream>
#include <vector>
#include "database_tools.h"

namespace WYLJUS002{

    std::vector<student_record> student_records; //Prehaps define this in the header class?

    //Functions
    void add_student(){
    std::cout << "Add student function\n";
    }

    void read_database(){
        std::cout << "Read from database\n";
    }

    void save_database(){
        std::cout << "Save the database\n";
    }

    void disp_student(){
        std::cout << "Display student data\n";
    }

    void grade_student(){
        std::cout << "Grade a student\n";
    }
}