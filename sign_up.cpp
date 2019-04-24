#include <iostream>
#include <fstream>
#include "global_data.h"
using namespace std;

bool sign_up()
{
	user u;
	std::cout << "Enter UID: ";
	std::cin >> u.id;
	if(search_identifier(u.id, "UserInfo.txt")){
		cout<<"User already exists.\n";
		return false;
	}
	int choice;
	cout<<"Are you a - \n";
	cout<<"1 - Student\n2 - Instructor\n";
	cout<<"Enter choice: ";
	cin>>choice;
	if(choice==1)
		u.category="Student";
	else
		u.category="Instructor";
	cout<<"Enter Email ID: ";
	cin>>u.email;
	cout<<"Enter First Name: ";
	getline(cin, u.fname);
	getline(cin, u.fname);
	cout<<"Enter Last Name: ";
	getline(cin, u.lname);
	cout<<"Enter Password: ";
	getline(cin, u.password);
	string user_info=u.id+" "+u.password+" "+u.email+" "+u.category+" "+u.fname+" "+u.lname;
	if(add_line_in_file(user_info, "UserInfo.txt")){
		cout<<"Sign Up Successful!\n";
		return true;
	}else{
		cout<<"Sign Up Failed.\n";
		return false;
	}
}
