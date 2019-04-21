#include <iostream>
#include <fstream>
#include "useful_functions.h"
using namespace std;

bool sign_up()
{
	std::cout << "Enter UID: ";
	string UID, email, fname, lname, category, gender;
	std::cin >> UID;
	if(find_line_in_file(UID, "UIDList")){
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
	string command="./add_user.sh "+UID+" "+UID+" "+email+" "+category+" "+fname+" "+lname;
	system(command.c_str());
	ifstream check("Users/"+UID+"/info.txt");
	if(check.is_open()){
		add_line_in_file(UID, "UIDList");
		cout<<"Account successully created.\n";
		return true;
	}else{
		cout<<"Sign Up failed.\n";
	}
}
