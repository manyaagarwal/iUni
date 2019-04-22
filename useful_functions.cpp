#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*string[] get_array_from_line(ifstream &fin)
{
	string line;
	getline(fin, line);
	stringstream ss(line);
}

string[] get_info(string id, string file)
{
	std::ifstream fin(file, std::ios::in);
	string info[] = new string[]("0000");
	if (fin.is_open()) {
		string line;
		while (std::getline(fin, line)) {
			stringstream ss(line);

			if(line[id.size()]==' '){
				return true;
			}else{
				return false;
			}
		}
		fin.close();
	}
	else {
		std::cerr << "Unable to open file\n";
		return false;
	}
}
*/
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
		std::cerr << "Unable to open file\n";
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
