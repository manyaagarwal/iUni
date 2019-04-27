#ifndef GLOBAL_DATA_H
#define GLOBAL_DATA_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct user {
	string id, password, email, category, fname, lname;
    vector <string> courses;
};

struct course {
    string id, name, des;
    int num_assignment;
    user instructor;
};
extern user this_user;
extern bool in_session;
extern course this_course;

bool get_user_info(string id, user &u);

bool search_identifier(string, string);

bool add_line_in_file(string s, string file);

bool find_line_in_file(string s, string file);

string get_line_from_file(string s, string file);

void edit_file(string id, string newline, string file);

void print_vector(vector<string> &input);

#endif
