#include <iostream>
#include <string>
#include "Headerfiles\interface.hpp"
#include "Headerfiles\admin.hpp"
#include "Headerfiles\student.hpp"

// interface, admin and student are user made header files.

void screen();

int main()
{
    screen();            // keeping the main code as simple as possible.
    return 0;    
}

void screen()
{
    inter::screen();
    Admin* admin = new Admin;
    Student* S =  new Student;
    
    switch(inter::choice)
    {
        case 1:
        S->choice();
        break;

        case 2:
        admin->run();
        admin->saveToFile();
        break;

        case 3:
        std::cout << "Thank you for using the program.";
        exit(1);
        break;

        default:
        std::cout << "Tf do you not know how to type or you some sort of blind mfer?" << std::endl;
        break;
    }

    delete[] admin, S;
}

