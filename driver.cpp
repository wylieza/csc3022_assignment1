#include <iostream>
#include <fstream>

#include "database_tools.h"

    std::string menu[8] = {"\n>>>> MAIN MENU <<<<\n", "0: Add student",
                            "1: Read database", "2: Save database",
                            "3: Display given student data", 
                            "4: Grade student", "q: Quite\n",
                            "Enter a number (or q to quit) and press return..."};

    char menu_selection;

int main(void){

    for(;;){
        //Print menu out
        for (int i = 0; i < sizeof(menu)/sizeof(*menu); i++){
            std::cout << menu[i] << "\n";
        }

        //Process input
        std::cin >> menu_selection;
        if (!std::isdigit(menu_selection)){
            return 0;
        }

        std::cout << "\n";

        switch ((int) (menu_selection - '0')){
            case 0:
                //Add student
                WYLJUS002::add_student();
                break;

            case 1:
                WYLJUS002::read_database();
                break;

            case 2:
                WYLJUS002::save_database();
                break;

            case 3:
                WYLJUS002::disp_student();
                break;

            case 4:
                WYLJUS002::grade_student();
                break;

            default:
                std::cout << "Invalid Option Selected";
        }

        
    }
};