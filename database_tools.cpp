
#include <iostream>
#include <vector>
#include "database_tools.h"

namespace WYLJUS002{

    std::vector<student_record> student_records; //Prehaps define this in the header class?

    //Functions
    void add_student(void){
        std::vector<std::string> details;
        std::string name;
        std::string surname;
        std::string student_no;
        std::string student_record;

        std::cout << ">> Enter data for new student <<\n";

        std::cout << "Student name: ";
        std::cin >> name;

        std::cout << "\nStudent Surname: ";
        std::cin >> surname;

        std::cout << "\nStudent number: ";
        std::cin >> student_no;
       
        std::cout << "\nClass record: ";
        std::cin.ignore();
        getline(std::cin, student_record);
        

        add_student(name, surname, student_no, student_record);
    }

    void add_student(std::string name, std::string surname, std::string student_no, std::string class_record){
        std::cout << "Add student function\n";
        student_record record;
        record.name = name;
        record.surname = surname;
        record.student_no = student_no;
        record.class_record = class_record;

        if(unique_student(record)){
            student_records.push_back(record);
            std::cout << "\n>>> Student data added succesfully <<<\n";
        }else{
            std::cout << "\n>>> Student already in database! <<<\n";
        }
    }

    void read_database(){
        std::cout << "Read from database\n";
    }

    void save_database(){
        std::cout << "Save the database\n";
    }

    void disp_student(std::string student_no){
        std::cout << "Display student data\n";

        for (int i =0; i < student_records.size(); i++){
            if (student_no.compare(student_records[i].student_no) == 0){
                print_student(student_records[i]);
            }
        }
    }

    void grade_student(){
        std::cout << "Grade a student\n";
    }

    bool unique_student(student_record record){
        for (int i =0; i < student_records.size(); i++){
            if (record.student_no.compare(student_records[i].student_no) == 0){
                return false;
            }
        }
        return true;
    }

    void print_student(student_record record){
        std::cout << "\n >>> Student Data <<<\n";
        std::cout << "Name: " << record.name << "\n";
        std::cout << "Surname: " << record.surname << "\n";
        std::cout << "Student Number: " << record.student_no << "\n";
        std::cout << "Student's record: " << record.class_record << "\n";

    }
}