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
	sign_in(u);
}
