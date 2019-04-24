#include <iostream>
#include <fstream>
#include "sign_in.h"
#include "sign_up.h"
#include "global_data.h"
#include "search_people.h"
#include "edit_details.h"
#include "student.h"
using namespace std;

int main()
{
	in_session = sign_in(this_user);
	if (in_session) {
		cout<<"Hi "<<this_user.fname<<"! Welcome Back\n";
	}else{
		std::cout << "Sign In Failed." << '\n';
		return 0;
	}
	if(this_user.category=="Student"){
		student_home_page();
	}else if (this_user.category=="Instructor") {
		//instructor_home_page
	}else{
		std::cout << "Error 404" << '\n';
	}
}
