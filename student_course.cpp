#include <iostream>
#include <fstream>
#include "global_data.h"
#include "assignments.h"
#include "courses.h"
using namespace std;

void student_course_menu(){
    while(true)
    {
        std::cout << "Welcome " <<this_user.fname<< "!\n";
        std::cout << "1 - View Course Details" << '\n';
        std::cout << "2 - Download Assignment" << '\n';
        std::cout << "3 - View Grade" << '\n';
        std::cout << "0 - Go Back" << '\n';
        std::cout << "Select Your Choice: " << '\n';
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                view_details(this_course.id);
                break;
            case 2:
                download_assignment();
                break;
            case 3:
                view_grade_student();
                break;
            case 0:
                return;
            default:
                std::cout<<"Invalid choice!\n";
        }
    }
}

