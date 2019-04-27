#include <iosteam>
#include <fstream>
#include "global_data.h"
#include "assignments.h"
#include "courses.h"

void instructor_course_menu(){
    while(true)
    {
        std::cout << "Welcome " <<this_user.fname<< "!\n";
        std::cout << "1 - View Course Details" << '\n';
        std::cout << "2 - Edit Course Details" << '\n';
        std::cout << "3 - Add Assignment" << '\n';
        std::cout << "4 - Remove Assignment" << '\n';
        std::cout << "5 - Grade Assignment" << '\n';
        std::cout << "6 - Add Quiz" << '\n';
        std::cout << "7 - View Quiz Grades" << '\n';
        std::cout << "0 - Go Back" << '\n';
        std::cout << "Select Your Choice: " << '\n';
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                view_details(this_course.id);
                break;
            case 2:
                edit_details(this_course);
                break;
            case 3:
                upload_assignment();
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 0:
                return;
            default:
                std::cout<<"Invalid choice!\n";
        }
    }
}
