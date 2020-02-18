
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "database_tools.h"

namespace WYLJUS002{

    std::vector<student_record> student_records;
    std::vector<std::string> details;

    //Functions
    void add_student(void){
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
        std::cout << "\n>>> Adding student to database <<<\n";
        student_record record;
        record.name = name;
        record.surname = surname;
        record.student_no = student_no;
        record.class_record = class_record;

        if(unique_student(record)){
            student_records.push_back(record);
            std::cout << "Student data added succesfully\n";
        }else{
            std::cout << "WARN: Student already in database!\n";
        }
    }

    void read_database(){
        std::cout << "Reading from database...\n";

        std::string line;
        int pos;
        int count;
        std::ifstream database("database.txt");

        if(database.is_open()){
            while(getline(database, line)){
                while(pos >= 0){
                    if (count++ < 3){
                        pos = line.find(" ");
                        details.push_back(line.substr(0, pos));
                        line.erase(0, pos+1);
                    }else{
                        details.push_back(line);
                        pos = -1;
                    }
                }
                add_student(details[0], details[1], details[2], details[3]);
                details.clear();
                pos = 0;
                count = 0;
            }
            database.close();
            std::cout << "\nReading success!...\n";
        }else{
            std::cout << "Error occured, could not access database file";
        }


    }

    void save_database(){
        read_database();
        std::cout << "\nWriting to the database file...\n";

        std::ofstream database("database.txt");

        if(database.is_open()){
            for (int i =0; i < student_records.size(); i++){
                database << student_records[i].name << " ";
                database << student_records[i].surname << " ";
                database << student_records[i].student_no << " ";
                database << student_records[i].class_record << "\n";
            }
            database.close();
            std::cout << "\nSaving success!...\n";
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
                std::cout << "Student's grade: " << calc_grade(student_records[i].class_record) << "\n";
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
            }
        }
        return average/count;
    }
}