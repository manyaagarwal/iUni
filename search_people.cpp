#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "global_data.h"

using namespace std;

void search_users()
{
  string s;
  cout<<"Enter Keyword To Search For People: ";
  cin>>s;
  std::ifstream fin("UserInfo.txt", std::ios::in);
  if (fin.is_open()) {
    std::string line,line_l;
    user u;
    for(int i=0;i<s.size();i++){
      s[i]=tolower(s[i]);
    }
    while (std::getline(fin, line)) {
      line_l=line;
      stringstream ss(line);
      ss>>u.id>>u.password>>u.email>>u.category>>u.fname>>u.lname;
      line_l = u.id+" "+u.email+" "+u.category+" "+u.fname+" "+u.lname;
      for(int i=0;i<line_l.size();i++){
        line_l[i]=tolower(line_l[i]);
      }
      if(line_l.find(s)!=string::npos){
        cout<<u.fname<<" "<<u.lname<<" "<<u.category<<" "<<u.email<<"\n";
      }
    }
    fin.close();
  }
  else {
    std::cerr << "Unable to open file\n";
  }
}
