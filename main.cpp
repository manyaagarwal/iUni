#include <iostream>
#include <fstream>
#include "sign_in.h"
#include "sign_up.h"
#include "useful_functions.h"

using namespace std;

int main()
{
	string id;
	cin>>id;
	user u;
	cout<<get_user_info(id, u)<<"\n";
	cout<<u.id<<" "<<u.password<<" "<<u.email<<" "<<u.category<<" "<<u.fname<<" "<<u.lname<<"\n";
}
