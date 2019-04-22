#include <iostream>
#include <fstream>
#include "useful_functions.h"
using namespace std;

bool sign_up()
{
	std::cout << "Enter UID: ";
	string UID, email, fname, lname, category, gender, password;
	std::cin >> UID;
	if(search_identifier(UID, "UserInfo.txt")){
		cout<<"User already exists.\n";
		return false;
	}
	int choice;
	cout<<"Are you a - \n";
	cout<<"1 - Student\n2 - Instructor\n";
	cout<<"Enter choice: ";
	cin>>choice;
	if(choice==1)
		category="Student";
	else
		category="Instructor";
	cout<<"Enter Email ID: ";
	cin>>email;
	cout<<"Enter First Name: ";
	getline(cin, fname);
	getline(cin, fname);
	cout<<"Enter Last Name: ";
	getline(cin, lname);
	cout<<"Enter Password: ";
	getline(cin, password);
	string user_info=UID+" "+password+" "+email+" "+category+" "+fname+" "+lname;
	if(add_line_in_file(user_info, "UserInfo.txt")){
		cout<<"Sign Up Successful!\n";
		return true;
	}else{
		cout<<"Sign Up Failed.\n";
		return false;
	}
}
