#include <iostream>
#include <fstream>
#include "global_data.h"
#include "edit_details.h"
#include "search_people.h"
using namespace std;

void instructor_home_page()
{
  std::cout << "Welcome " <<this_user.fname<< "!\n";
  std::cout << "1 - View Courses" << '\n';
  std::cout << "2 - Create A Course" << '\n';
  std::cout << "4 - View Student Grades" << '\n';
  std::cout << "4 - Search People" << '\n';
  std::cout << "5 - Edit Personal Details" << '\n';
  std::cout << "Select Your Choice: " << '\n';
  int choice;
  std::cin >> choice;
  switch (choice) {
    case 1:
      //View Courses
    case 2:
      //Enrollol
    case 3:
      //View Grades
    case 4:
      search_users();
      break;
    case 5:
      edit(this_user);
      break;
  }
}
