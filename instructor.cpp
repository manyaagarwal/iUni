#include <iostream>
#include <fstream>
#include "global_data.h"
#include "edit_details.h"
#include "courses.h"
#include "search_people.h"
#include "instructor_course.h"
using namespace std;

void instructor_home_page()
{
  while (true) {
  std::cout << "Welcome " <<this_user.fname<< "!\n";
  std::cout << "1 - View Courses" << '\n';
  std::cout << "2 - Create A Course" << '\n';
  std::cout << "3 - View Student Grades" << '\n';
  std::cout << "4 - Search People" << '\n';
  std::cout << "5 - Edit Personal Details" << '\n';
  std::cout << "0 - Sign Out" << '\n';
  std::cout << "Select Your Choice: " << '\n';
  int choice;
  std::cin >> choice;
  switch (choice) {
    case 1:
      view_created_courses();
      break;
    case 2:
      if (addCourse()){
          char ch;
          cout<<"Course was successfully created.\nDo you wish to view more options related to the course?(Y/N)\n";
          cin>>ch;
          if(ch == 'Y'){
              instructor_course_menu(this_course.id);
          }
      }
      else{
          cout<<"Course cannot be created";
      }
      break;
    case 3:
      view_grades();
      break;
    case 4:
      search_users();
      break;
    case 5:
      edit(this_user);
      break;
    case 0:
      in_session=false;
      std::cout << "Signed Out Successfully!" << '\n';
      return;
    default:
      std::cout << "Invalid Choice" << '\n';
  }
  }
}
