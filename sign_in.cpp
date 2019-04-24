#include <iostream>
#include <fstream>
#include "global_data.h"
using namespace std;


bool sign_in(user &u)
{
	cout<<"Enter UID: ";
	string id, pwd, temp;
	cin>>id;
	if(get_user_info(id, u)){
		cout << "Enter Password: ";
		getline(cin, temp);
		getline(cin, pwd);
		if (pwd == u.password) {
			std::cout << "Signed In Successfully." << '\n';
			return true;
		}else{
			cout<<"Incorrect Password.\n";
			return false;
		}
	}else{
		cout<<"User Not Found.\n";
		return false;
	}
}
