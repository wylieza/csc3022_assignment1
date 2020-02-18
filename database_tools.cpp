
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
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
        std::cout << "Saving the database...\n";

        std::ofstream database("database.txt");

        if(database.is_open()){
            for (int i =0; i < student_records.size(); i++){
                database << student_records[i].name << " ";
                database << student_records[i].surname << " ";
                database << student_records[i].student_no << " ";
                database << student_records[i].class_record << "\n";
            }
            database.close();
        }else{
            std::cout << "Error occured, could not access database file";
        }
        

    }

    void disp_student(void){
        std::string student_no;

        std::cout << "\nStudent number: ";
        std::cin >> student_no;

        disp_student(student_no);
    }

    void disp_student(std::string student_no){
        std::cout << "Display student data\n";
        bool found = false;

        for (int i =0; i < student_records.size(); i++){
            if (student_no.compare(student_records[i].student_no) == 0){
                found = true;
                print_student(student_records[i]);
            }
        }
        if(!found){
            std::cout << "\nSorry, No record of student exists\n";
        }
    }

    void grade_student(){
        std::cout << "\n>>> Grade a student <<<\n";
        std::string student_no;

        bool found = false;
        std::cout << "Student number: ";
        std::cin >> student_no;

        for (int i =0; i < student_records.size(); i++){
            if (student_no.compare(student_records[i].student_no) == 0){
                found = true;
                std::cout << "Student's grade: " << calc_grade(student_records[i].class_record);
            }
        }
        if(!found){
            std::cout << "\nSorry, No record of student exists\n";
        }
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

    double calc_grade(std::string cr){
        std::stringstream str_stream;
        double average = 0;
        int itemp_holder;
        std::string stemp_holder;
        double count = 0;

        str_stream << cr;

        while(! str_stream.eof()){
            str_stream >> stemp_holder;

            if(std::stringstream(stemp_holder) >> itemp_holder){
                count++;
                average += itemp_holder;
                std::cout << average;
            }
        }
        return itemp_holder/count;
    }
}