#include <iostream>
#include <fstream>
#include "useful_functions.h"
using namespace std;


bool sign_in(user &u)
{
	cout<<"Enter UID: ";
	string id;
	cin>>id;
	if(get_user_info(id, u)){
		cout<<"Signed In Successfully.\n";
		return true;
	}else{
		cout<<"Failed To Sign In. Try Again.\n";
		return false;
	}
}
