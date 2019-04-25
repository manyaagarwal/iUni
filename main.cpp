#include <iostream>
#include <fstream>
#include "sign_in.h"
#include "sign_up.h"
#include "global_data.h"
#include "search_people.h"
#include "edit_details.h"
#include "student.h"
#include "instructor.h"
using namespace std;

int main()
{
	while (true) {
		std::cout << "1 - Sign In" << '\n';
		std::cout << "2 - Sign Up" << '\n';
		std::cout << "0 - Exit" << '\n';
		std::cout << "Select choice: ";
		int choice;
		std::cin >> choice;
		switch (choice) {
			case 1:
				in_session = sign_in(this_user);
				if (in_session) {
					cout<<"Hi "<<this_user.fname<<"! Welcome Back\n";
					if(this_user.category=="Student"){
						student_home_page();
					}else if (this_user.category=="Instructor") {
						instructor_home_page();
					}else{
						std::cout << "Error 404" << '\n';
					}
				}else{
					std::cout << "Sign In Failed." << '\n';
				}
				break;
			case 2:
				sign_up();
				break;
			case 0:
				return 0;
			default:
				std::cout << "Invalid Choice" << '\n';
		}
	}
}
