#include <fstream>
#include <iostream>
using namespace std;

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
