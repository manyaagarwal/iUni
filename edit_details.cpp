#include <fstream>
#include <string>
#include "useful_functions.h"
#include <cstdlib>
using namespace std;

void edit(user &u)
{
  cout << "1 - Email:\t"<< u.email << '\n';
  cout << "2 - First Name:\t"<< u.fname << '\n';
  cout << "3 - Last Name:\t"<< u.lname << '\n';
  cout << "4 - Password:\t******\n";
  cout << "Select the field you need to edit: ";
  int choice;
  cin>>choice;
  string email, fname, lname, pwd;
  switch (choice) {
    case 1:
      cout << "Enter new Email: ";
      cin>>u.email;
      break;
    case 2:
      cout << "Enter new First Name: ";
      cin>>u.fname;
      break;
    case 3:
      cout << "Enter new Last Name: ";
      cin>>u.lname;
      break;
    case 4:
      cout << "Enter new Password: ";
      cin>>u.password;
      break;
  }
  ifstream fin("UserInfo.txt");
  ofstream fout("temp.txt");
  if (fin.is_open()) {
    std::string line;
    while (std::getline(fin, line)) {
      if(line.find(u.id+" ")==0){
        fout<<u.id+" "+u.password+" "+u.email+" "+u.category+" "+u.fname+" "+u.lname<<"\n";
      }else{
        fout<<line<<"\n";
      }
    }
    remove("UserInfo.txt");
    rename("temp.txt", "UserInfo.txt");
    fin.close();
    fout.close();
  } else {
    std::cerr << "Edit Failed\n";
  }
}
