#ifndef ADMIN
#define ADMIN

/*  This header files include all the functionality related to teacher/admin side. */

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
// must have header files

#define line(x) std::cout << "\n\n\t\t\t\t\t " << x;

class Admin
{
  int choice;
  int count = 1;

  struct Student
  {
    int roll;
    std::string name;
    std::string course;
    float percent;
  };

  std::string Name, Course;
  int Roll;
  float Percent;

  std::vector<Student> info;

public:
  void screen();     // Choice screening
  void addData();    // too add the data of one more student or add another student
  void deleteData(); // to remove a student from database aka .csv file
  void choose();
  void run();
  void display(); // to display
  void search();
  void id_search();
  void name_search();
  void toLower(std::string str);
  void fixRole(int &id, std::string Course); // this function is made to prevent students having same roll number.
  void fixPercent(float &percentage, std::string dev);

  // FIle handling functions below:
  void saveToFile();
  void heading(); // only needed this for the first time to measure.
  void loadFromFile();
};

void Admin ::screen(void)
{
  system("cls");
  std::cout << "\t\t\t\t\t | Logged in as Administrator | " << std::endl;
  line("1. Add a student");
  line("2. Remove a student");
  line("3. Search a student");
  line("4. View Detailed Table");
  line("5. View Database");
  line("6. Exit");

  line("Enter your choice: ");
  std::cin >> choice;
}

void Admin::addData(void)
{
  std::cout << "Student " << count << std::endl;
  std::cout << "\nEnter the name: ";
  std::cin.ignore();
  std::getline(std::cin, Name);
  toLower(Name);

  std::cout << "\nEnter the Roll number: ";
  std::cin >> Roll;

  std::cout << "\nEnter the Course: ";
  std::cin.ignore();
  std::getline(std::cin, Course);
  toLower(Course);

  std::cout << "\nEnter the percentage: ";
  std::cin >> Percent;

  fixRole(Roll, Course);
  fixPercent(Percent, Name);
  info.emplace_back(Student{Roll, Name, Course, Percent});

  std::cout << std::endl;
  count++;
}

void Admin ::choose(void)
{
  system("cls");
  while (choice != 6)
  {
    switch (choice)
    {
    case 1:
      addData();
      break;

    case 2:
      deleteData();
      break;

    case 3:
      search();
      break;

    case 4:
      display();
      break;

    case 5:
      loadFromFile();
      break;

    case 6:
      std::cout << "I think the time has come goodbye";
      saveToFile();
      exit(1);
    }

    std::cout << "\n---------------------------------------------------------------------------" << std::endl;
    std::cout << "\n\t\t\t\t\tChoices Screen\n"
              << std::endl;
    std::cout << " 1. Add Student\n";
    std::cout << " 2. Delete Student\n";
    std::cout << " 3. Search a student\n";
    std::cout << " 4. Display all Records\n";
    std::cout << " 5. Show database\n";
    std::cout << " 6. Exit\n";
    std::cout << "\nEnter choice : ";
    std::cin >> choice;
  }
}

void Admin ::run(void)
{
  // heading();
  screen();
  choose();
}

void Admin ::display(void)
{
  std::cout << "\n\t\t\t\tDisplaying all students\n\n";
  int i = 1;
  std::cout << "S.no\t\t"
            << "Name\t\t\t"
            << "ID\t\t"
            << "Course\t\t"
            << "Percentage\n"
            << std::endl;

  for (auto it : info)
  {
    std::cout << i << "\t\t" << it.name << "\t\t" << it.roll << "\t\t" << it.course << "\t\t" << it.percent << "\n"
              << std::endl;
    i++;
  }
}

void Admin ::deleteData(void)
{
  int index_num;
  std::cout << "\nEnter the index number of the student: ";
  std::cin >> index_num;

  if (index_num > info.size())
  {
    std::cout << "No data stored at that index number.";
    // break;
  }
  else
  {
    info.erase(info.begin() + index_num);
    std::cout << "Data succesfully removed.";
  }
}

void Admin ::search(void)
{
  // this is going to be the biggest function i suppose
  // so i made the two sub functions for it hehe

  int s_choice;

  void toLower(std::string str);

  std::cout << "\nSearch by: " << std::endl;
  std::cout << "1. Roll no" << std::endl;
  std::cout << "2. Name" << std::endl;
  std::cout << "Enter: ";
  std::cin >> s_choice;

  std::cout << std::endl;

  switch (s_choice)
  {
  case 1:
    id_search();
    break;

  case 2:
    name_search();
    break;

  default:
    search();
    break;
  }
}

void Admin ::toLower(std::string str)
{
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] >= 65 && str[i] <= 90)
      str[i] = str[i] + 32;
  }
}

void Admin ::id_search(void)
{
  bool flag = false;
  uint16_t search_roll;

  std::cout << "\nEnter the roll number to search: ";
  std::cin >> search_roll;

  for (auto i : info)
  {
    if (i.roll == search_roll)
    {
      std::cout << "Student FOUND!\n";
      std::cout << "\nName: " << i.name << std::endl;
      std::cout << "\nRoll: '" << i.roll << "'" << std::endl;
      std::cout << "\nCourse: " << i.course << std::endl;
      std::cout << "\nPercentage: " << i.percent << std::endl;

      std::cout << std::endl;
      flag = true;
      break;
    }
  }

  if (!flag)
  {
    std::cout << "NO student found with the given roll number.\n";
  }
}

void Admin::name_search()
{
  bool flag = false;
  std::string search_name;

  std::cout << "\nEnter the name to search: ";
  std::cin.ignore();
  std::getline(std::cin, search_name);

  toLower(search_name);

  for (auto i : info)
  {
    if (i.name == search_name)
    {
      std::cout << "Student FOUND!" << std::endl;
      std::cout << "\nName: " << i.name << std::endl;
      std::cout << "Roll: " << i.roll << std::endl;
      std::cout << "Course: " << i.course << std::endl;
      std::cout << "Percentage: " << i.percent << std::endl;

      std::cout << std::endl;
      flag = true;
      break;
    }
  }

  if (!flag)
  {
    std::cout << "No student found with the given name." << std::endl;
  }
}

void Admin::heading()
{
  std::ofstream File("allStudents.txt");

  File << "\t\t\t\tDisplaying all students\n\n";
  File << "S.no\t\t"
       << "Name\t\t\t"
       << "ID\t\t"
       << "Course\t\t"
       << "Percentage\n"
       << std::endl;
}

void Admin ::saveToFile()
{
  std::ofstream data("allStudents.txt", std::ios::app);

  int i = 1;

  if (!data.is_open())
  {
    std::cout << "Unable to open the file.\n";
    return;
  }

  for (auto latestStudent : info)
  {
    data << latestStudent.roll << "\t\t" << latestStudent.name << "\t\t" << latestStudent.course << "\t\t" << latestStudent.percent << "\n"
         << std::endl;
  }

  data.close();
}

void Admin ::loadFromFile()
{
  std::ifstream data("allStudents.txt");

  if (!data.is_open())
  {
    std::cout << "Error file couldn't open.\n";
    return;
  }

  std::string all_students;

  while (std::getline(data, all_students))
  {
    std::cout << all_students << std::endl;
  }

  data.close();
}

void Admin ::fixRole(int &id, std::string Course)
{
  for (auto it : info)
  {
    if (id == it.roll)
    {
      if (Course == it.course)
      {
        id++;
      }
      else
      {
        id = id;
      }
    }
  }
};

void Admin ::fixPercent(float &percentage, std::string dev)
{
  std::string substring = "dev";
  size_t chuck = dev.find(substring);

  if (percentage > 100)
  {
    if (chuck != std::string::npos)
    {
      return;
    }
    else
    {
      percentage = 100;
    }
  }

  // made this function to change percent to 100 whenever user try to put a number greater than 100.
  // unless the name is dev.
};

#endif