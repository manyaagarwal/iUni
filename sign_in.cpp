#include <iostream>
#include <fstream>
using namespace std;

void acc_type_prp()
{
	cout<<"Sign in as a/an: \n";
	cout<<"Student - 1\n";
	cout<<"Instructor - 2\n";
}

void sign_in()
{
	acc_type_prp();
	int choice;
	cin>>choice;
	if(choice!=1&&choice!=2){
		cout<<"Invalid Selection. Try again\n";
		acc_type_prp();
		cin>>choice;
	}
	cout<<choice<<"\n";
}
