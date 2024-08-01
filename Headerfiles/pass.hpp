#ifndef PASS
#define PASS

/*
This header file is made to get username and password
- saving them to a file
- also reading from that file.
*/

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <cstring>
#include <map>

class password
{
private:
    std::string username;
    std::map<std::string, std::string> credentials; // not in use at the moment
    char p[9] = {0};                                // password
    char cp[9] = {0};                               // confirm password
    bool flag = false;
    unsigned int retries = 1;

public:
    std::string inputUsername;
    std::string getUsername()
    {
        return username;
    }

    std::string getPassword()
    {
        return p;
    }

    void setup()
    {
        std::cout << "NOTE: You only have 2 errors in case the password doesn't match.\n"
                  << "NOTE: Password should be of 8 digits only.\n\n"
                  << std::endl;

        std::cout << "Enter the Username: ";
        std::cin >> username;

        std::cout << "Enter the password: ";
        for (int i = 0; i < 8; i++)
        {
            p[i] = static_cast<char>(_getch());
            _putch('*');
        }

        p[8] = '\0'; // To terminate the string

        reEnter();
    }

    void reEnter();      // for confirming password
    void confirm();      // for checking whether the passwords are same or not
    void saveToFile();   // for saving to file duh
    void loadFromFile(); // To load username and password from file if any
    void login();
};

void password ::reEnter()
{
    std::cout << "\nConfirm your password: ";
    for (int i = 0; i < 8; i++)
    {
        cp[i] = static_cast<char>(_getch());
        _putch('*');
        /* this function is used to replace * with whatever character we put
        in character so it can look like genuine password. */ 
    }
    cp[8] = '\0';
}

void password ::confirm()
{
    for (int i = 0; i < 8; i++)
    {
        if (p[i] == cp[i])
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
    }

    if (flag)
    {
        std::cout << "\n\nPassword has been set.\n";
        saveToFile();
    }
    else if (flag == false)
    {
        while (retries != 3)
        {
            system("cls");
            std::cout << "Confirm password again [ Attempt " << retries << " ]" << std::endl;

            std::cout << "Passowrd: ********";
            reEnter();
            retries++;

            confirm();
        }

        if (retries < 3)
        {
            std::cout << "\n\nYou cannot pass due to security issues.";
        }
    }
}

void password::loadFromFile()
{
    std::ifstream file("credentials.txt");
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            if (line.find("Username: ") == 0)
            {
                username = line.substr(10); // Extract the username from the line
            }
            else if (line.find("Password: ") == 0)
            {
                std::string password = line.substr(10); // Extract the password from the line
                strcpy(p, password.c_str());            // Copy the password to the member variable
            }
        }
        file.close();
    }
    else
    {
        std::cout << "\n\nError opening file.\n";
    }
}

void password::saveToFile()
{
    std::string filename = "credentials.txt";

    std::ofstream file(filename, std::ios::app);
    if (file.is_open())
    {
        file << "Username: " << getUsername() << std::endl;
        file << "Password: " << getPassword() << std::endl;
        file << "\n";
        file.close();
    }
}

void password::login()
{
    std::string inputPassword;

    std::cout << "Enter the username: ";
    std::cin >> inputUsername;

    std::cout << "Enter the password: ";
    for (int i = 0; i < 8; i++)
    {
        inputPassword.push_back(static_cast<char>(_getch()));
        _putch('*');
    }
    inputPassword[8] = '\0';

    std::ifstream file("credentials.txt");
    if (file.is_open())
    {
        std::string line;
        std::string username;
        std::string password;
        bool found = false;
        while (std::getline(file, line))
        {
            if (line.find("Username: ") == 0)
            {
                username = line.substr(10); // Extract the username from the line
            }
            else if (line.find("Password: ") == 0)
            {
                password = line.substr(10); // Extract the password from the line

                if (username == inputUsername && password == inputPassword)
                {
                    found = true;
                    break;
                }
            }
        }
        file.close();

        if (found)
        {
            std::cout << "\n\nLogin successful. You may proceed.\n";
        }
        else
        {
            std::cout << "\n\nInvalid username or password. Access denied.\n";
        }
    }
    else
    {
        std::cout << "Error opening file.\n";
    }
}

// included the above function/code snippet in the student header file instead as it was more used there/

#endif