#include <iostream>
#include <fstream>

#include "driver.h"

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
        if (std::isdigit(menu_selection)){
            std::cout << menu_selection;
        }else{
            return 0;
        }

        
    }
};

