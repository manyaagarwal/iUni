#include <iostream>
#include <fstream>
#include "sign_in.h"
#include "sign_up.h"
#include "useful_functions.h"
#include "search_people.h"
#include "edit_details.h"

using namespace std;

user this_session;
bool in_session;

int main()
{
	in_session = sign_in(this_session);
	if (in_session) {
		cout<<"Hi "<<this_session.fname<<"! Welcome Back\n";
	}else{
		std::cout << "Sign In Failed." << '\n';
	}
}
