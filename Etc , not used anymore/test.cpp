// // #include <iostream>
// // #include <iomanip>
// // #include <string>
// // #include <vector>
// // #include <random>

// // using namespace std;

// // struct student
// // {
// //     int id, percent;
// //     std::string name;
// // };

// // class test1
// // {
// // public:
// //     vector<student> v;
// //     void add(int ID, int Percent, string Name)
// //     {
// //         v.push_back(student{ID, Percent, Name});
// //     }

// //     void display();
// // };

// // void test1::display()
// // {
// //     int count = 1;
// //     cout << "S.no\t\t" << "Name" << setw(20) << "ID" << setw(10) << "Percent\n" << std::endl;
// //     for (auto i : v)
// //     {
// //         std::cout << count << "\t\t" << i.name << setw(20) << i.id << setw(10) << i.percent << "\n" << std::endl;
// //         count++;
// //     }   
// // }

// // int main()
// // {
// //     test1 T;
// //     T.add(4, 100, "Gotei sharma");
// //     T.add(44, 13, "Pintu");
// //     T.display();
// //     std::cin.get();
// // }
// // #include <iostream>
// // #include <cstdlib>

// // #ifdef _WIN32
// // #include <windows.h>
// // #else
// // #include <sys/stat.h>
// // #endif

// // bool createDirectory(const std::wstring& path) {
// // #ifdef _WIN32
// //     if (CreateDirectoryW(path.c_str(), nullptr) || GetLastError() == ERROR_ALREADY_EXISTS) {
// //         return true;
// //     }
// // #else
// //     if (mkdir(path.c_str(), 0777) == 0) {
// //         return true;
// //     }
// // #endif
// //     return false;
// // }

// // int main() {
// //     std::wstring folderName = L"StudentData";

// //     if (createDirectory(folderName)) {
// //         std::wcout << L"Directory created: " << folderName << std::endl;
// //     } else {
// //         std::wcout << L"Error creating the directory." << std::endl;
// //     }

// //     return 0;
// // }

// #include <string>
// #include <iostream>

// using namespace std;

// int main() {
//   // Create a new directory.
//   std::string directory_path = "/my_directory";
//   if (!std::filesystem::exists(directory_path)) {
//     std::filesystem::create_directory(directory_path);
//   }

//   // Create a new file in the directory.
//   std::string file_path = directory_path + "/myfile.txt";
//   ofstream file(file_path);

//   // Write some data to the file.
//   file << "This is some data.";

//   // Close the file.
//   file.close();

//   return 0;
// }
