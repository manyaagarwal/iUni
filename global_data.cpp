#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct user {
	string id, password, email, category, fname, lname;
};
struct course {
    string id,name,des;
    user instructor;
};

user this_user;
bool in_session = false;

bool get_user_info(string id, user &u)
{
	std::ifstream fin("UserInfo.txt", std::ios::in);
	if (fin.is_open()) {
		std::string line;
		while (std::getline(fin, line)) {
			stringstream ss(line);
			ss>>u.id>>u.password>>u.email>>u.category>>u.fname>>u.lname;
			if(u.id == id){
				return true;
			}
		}
		fin.close();
	}
	return false;
}

bool search_identifier(string id, string file)
{
	std::ifstream fin(file, std::ios::in);
	if (fin.is_open()) {
		std::string line;
		while (std::getline(fin, line)) {
			if(line.substr(0, id.size())==id && line[id.size()]==' '){
				return true;
			}
		}
		fin.close();
	}
	else {
		return false;
	}
	return false;
}

bool add_line_in_file(string s, string file)
{
	std::ofstream fout(file, std::ios_base::app);
	if (fout.is_open()) {
		fout << s <<"\n";
		fout.close();
		return true;
	}
	return false;
}


bool find_line_in_file(string s, string file)
{
	std::ifstream fin(file, std::ios::in);
	if (fin.is_open()) {
		std::string line;
		while (std::getline(fin, line)) {
			if(line.compare(s)==0)
				return true;
		}
		fin.close();
	}
	return false;
}
