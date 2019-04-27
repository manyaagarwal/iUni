#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

struct user {
	string id, password, email, category, fname, lname;
	vector <string> courses;
};
struct course {
    string id,name,des;
    int num_assignment;
    user instructor;
};

user this_user;
course this_course;
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

bool get_course_info(string id, course &c)
{
	std::ifstream fin("CourseInfo.txt", std::ios::in);
	if (fin.is_open()) {
		std::string line;
		while (std::getline(fin){
			vector<string> words;
			string word;
			for(int i=0;i<line.size();i++){
				if(line[i]!='\t'){
					word+=line[i];
				}else{
					words.push_back(word);
				}
			}
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

string get_line_from_file(string id, string file)
{
    ifstream fin(file, std::ios::in);
    if (fin.is_open()) {
        string line;
        while (std::getline(fin, line)) {
            if(line.substr(0, id.size())==id && line[id.size()]==' '){
                return line;
            }
        }
        fin.close();
    }
    else {
        return "";
    }
    return "";
}

void edit_file(string id, string newline, string file)
{
    std::ifstream fin(file);
    std::ofstream fout("temp.txt");
    if (fin.is_open()) {
        std::string line;
        while (std::getline(fin, line)) {
            if(line.substr(0, id.size())==id && line[id.size()]==' '){
                fout<<newline<<endl;
            }
            else {
                fout<<line<<endl;
            }
        }
        fin.close();
    }
    remove(file.c_str());
    rename("temp.txt",file.c_str());
}

void print_vector(vector<string> &input)
{
    for (int i=0; i<input.size(); i++)
        cout<<i+1<<". "<<input.at(i)<<endl;
}
