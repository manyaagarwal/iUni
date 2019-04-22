#ifndef  USEFUL_FUNCTIONS_H
#define USEFUL_FUNCTIONS_H

#include <fstream>
#include <iostream>
using namespace std;

struct user {
  string id, password, email, category, fname, lname;
};

bool get_user_info(string id, user &u);

bool search_identifier(string, string);

bool add_line_in_file(string s, string file);

bool find_line_in_file(string s, string file);

#endif
