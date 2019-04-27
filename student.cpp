
#include <iostream>
#include <fstream>
#include "global_data.h"
#include "edit_details.h"
#include "search_people.h"
#include "courses.h"
#include "student_course.h"
using namespace std;

void student_home_page()
{
  while (true) {
  std::cout << "Welcome " <<this_user.fname<< "!\n";
  std::cout << "1 - View Courses" << '\n';
  std::cout << "2 - Enroll In Courses" << '\n';
  std::cout << "3 - View Grades" << '\n';
  std::cout << "4 - Search People" << '\n';
  std::cout << "5 - Edit Personal Details" << '\n';
  std::cout << "0 - Sign Out" << '\n';
  std::cout << "Select Your Choice: " << '\n';
  int choice;
  std::cin >> choice;
  switch (choice) {
    case 1:
      view_enrolled_courses();
      break;
    case 2:
        if (enrollCourse()){
            char ch;
            cout<<"Course was successfully added.\nDo you wish to view more options related to the course?(Y/N)\n";
            cin>>ch;
            if(ch == 'Y'){
                student_course_menu();
            }
        }
        else{
            cout<<"Course cannot be created";
        }


      break;
    case 3:
      view_grade_student();
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

