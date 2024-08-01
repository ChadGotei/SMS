#ifndef INTERFACE
#define INTERFACE

/* 
    This is a small header file for screen funtion and choice.
    We could have done this in main.cpp as well but we need to have clean code as well.
*/

#include <iostream>
#include <string>
#include <windows.h>

#define i_line(x) std::cout << "\n\n\n\t\t\t\t\t" << x << std::endl;

namespace inter
{
    int choice;
    
    void screen()
    {
        system("cls");
        // fflush(stdin);
        system("color 03");

        std::cout << "\n\n\n\t\t\t\t\t Student Record Management System" << std::endl;
        i_line("1. Student")
        i_line("2. Admin\\Teacher");
        i_line("3. Exit")

        std::cout << "\n\n\n\t\t\t\t\t" << "Enter choice: ";
        std::cin >> choice;
    }
}

// checking whether the user made header files are working fine or not was also one of the uses of this header file.

#endif // INTERFACE