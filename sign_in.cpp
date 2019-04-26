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
		std::ofstream fout("filename.txt", std::ios::out);
		if (fout.is_open()) {
			fout<<temp<<"\n"<<u.password<<"\n"<<pwd<<"\n";
			fout.close();
		}
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
