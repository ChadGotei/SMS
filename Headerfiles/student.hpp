#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include "pass.hpp"

#define nl file << std::endl;
// in this header file all the functions related to the student side are present.

class Student
{
public:
    void choice();

    // these functions are like functions where the code will be sumarising and will be calling other functions in them.
    void run();
    void run_new();
    void run_load();
    // void seperateFile();
    void random_data(); // to assign random data to the students to make it look realistic
    void storeData(const std::string &username);
    void loadFromFile(const std::string &username);

    ~Student()
    {
        delete[] Pass;
    }

    password *Pass = new password;
};

void Student ::choice(void)
{
    system("cls");
    std::cout << "\t\t\t\t\t\t | Logged in as Student |" << std::endl;
    run();
}

void Student ::run_new()
{
    Pass->setup();
    Pass->confirm();

    std::cout << "\nGathering information wait";
    for (int i = 0; i < 3; i++)
    {
        std::cout << ".";
        sleep(1);
    }
    system("cls");

    std::string filename = Pass->getUsername();

    srand(static_cast<unsigned int>(time(0)));

    random_data();
    storeData(filename);
    getch();
}

void Student ::run_load()
{
    Pass->login();
    std::cout << "\n\t\tPress any key to check your data.";
    getch();
    system("cls");

    std::string username = Pass->inputUsername;
    loadFromFile(username);
    getch();
}

void Student ::run()
{
    int choice;
    std::cout << "\t\t\t\t[1] New \t\t"
              << "[2] Load\t\t"
              << "[3] Exit\n"
              << std::endl;
    std::cout << "\t\t\t\tEnter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");
        run_new();
        break;

    case 2:
        system("cls");
        run_load();
        break;

    case 3:
        std::cout << "\nAdios friends.";
        exit(1);

    default:
        std::cout << "Tf is wrong with you can't you type";
        break;
    }
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

// to gather date for DOB ^

std::string generateRandomDOB()
{
    int day = getRandomNumber(1, 31);
    int month = getRandomNumber(1, 12);
    int year = getRandomNumber(1993, 2023);

    std::string dob = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
    return dob;
}

float generateRandomAttendance()
{
    return static_cast<float>(getRandomNumber(30, 100));
}

// this is for random attendance

std::string generateRandomCity()
{
    std::vector<std::string> cities = {"Mumbai", "Delhi", "Bangalore", "Chennai", "Kolkata", "Hyderabad", "Pune", "Bangladesh", "Ramesh Nagar"};

    return cities[getRandomNumber(0, 8)];
}

int getRandomRoll()
{
    return static_cast<int>(getRandomNumber(1, 69));
}

std::string getRandomCourse()
{
    std::vector<std::string> courses = {"BCA", "Maths hons", "Diploma", "Btech", "MCA", "B.com"};
    // added bcom because deep down i am stll a commerce student and maths hons because maths is bae.

    return courses[getRandomNumber(0, 5)];
}

float getRandomPercent()
{
    return static_cast<float>(getRandomNumber(25, 100));
}

std::string percentStatus(float percent, std::string &status)
{
    if (percent < 32)
    {
        status = "FAILED";
    }
    else if (percent > 33 && percent < 40)
    {
        status = "Grace marking";
    }
    else if (percent > 90)
    {
        status = "Topped!";
    }
    else
    {
        status = "Passed";
    }
}

std::string attendanceStatus(float attend, std::string &status)
{
    if (attend < 60)
    {
        status = "Poor";
    }
    else if (attend > 60 && attend < 90)
    {
        status = "Good";
    }
    else if (attend > 90)
    {
        status = "Excellent";
    }
}

void Student ::random_data()
{
    std::string status_att; // status of attendance.
    std::string status_percent;
    std::string DOB = generateRandomDOB();
    std::string City = generateRandomCity();
    float attend = generateRandomAttendance();
    int roll = getRandomRoll();
    std::string course = getRandomCourse();
    float percent = getRandomPercent();

    percentStatus(percent, status_percent);
    attendanceStatus(attend, status_att);

    // now displaying all the information.

    std::cout << "\t\t\t\t"
              << "Personal Details\n\n"
              << std::endl;
    std::cout << "\t\t"
              << "Username: \t" << Pass->getUsername() << "\n"
              << std::endl;
    std::cout << "\t\t"
              << "Roll number \t: " << roll << "\n"
              << std::endl;
    std::cout << "\t\t"
              << "Attendance: \t" << attend << " ," << status_att << "\n"
              << std::endl;
    std::cout << "\t\t"
              << "Percentage: \t" << percent << " ," << status_percent << "\n"
              << std::endl;
    std::cout << "\t\t"
              << "DOB: \t\t" << DOB << "\n"
              << std::endl;
    std::cout << "\t\t"
              << "City: \t" << City << "\n"
              << std::endl;
    std::cout << "\t\t"
              << "Couse: \t" << course << "\n"
              << std::endl;

    std::cout << std::endl;
}

void Student ::storeData(const std::string &username)
{
    std::string filename = username + ".txt";
    std::ofstream file(filename);

    if (file.is_open())
    {
        std::string status_att;
        std::string status_percent;
        std::string DOB = generateRandomDOB();
        std::string City = generateRandomCity();
        float attend = generateRandomAttendance();
        int roll = getRandomRoll();
        std::string course = getRandomCourse();
        float percent = getRandomPercent();

        percentStatus(percent, status_percent);
        attendanceStatus(attend, status_att);

        file << "\t\t"
             << "Information of " << username << std::endl;
        nl nl

                file
            << "Username: " << username << std::endl;
        nl
                file
            << "Roll number: " << roll << std::endl;
        nl
                file
            << "Attendance: " << attend << ", " << status_att << std::endl;
        nl
                file
            << "Percentage: " << percent << ", " << status_percent << std::endl;
        nl
                file
            << "DOB: " << DOB << std::endl;
        nl
                file
            << "City: " << City << std::endl;
        nl
                file
            << "Course: " << course << std::endl;
        nl

            file.close();
        // std::cout << "\t\tStudent data stored in file: " << filename << std::endl;
    }
    else
    {
        std::cout << "Error creating or opening file." << std::endl;
    }
}

void Student ::loadFromFile(const std::string &username)
{
    std::string filename = username + ".txt";
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Error, file could not open.\n";
    }

    std::string alldata;

    while (std::getline(file, alldata))
    {
        std::cout << alldata << std::endl;
    }

    file.close();
}

#endif // STUDENT