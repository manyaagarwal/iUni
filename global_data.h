#ifndef GLOBAL_DATA_H
#define GLOBAL_DATA_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct user {
	string id, password, email, category, fname, lname;
};

extern user this_user;
extern bool in_session;

bool get_user_info(string id, user &u);

bool search_identifier(string, string);

bool add_line_in_file(string s, string file);

bool find_line_in_file(string s, string file);

#endif
