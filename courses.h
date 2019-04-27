#ifndef COURSES
#define COURSES value
#include <iostream>
#include <fstream>
#include <string>
#include "global_data.h"
using namespace std;

bool addCourse();
bool enrollCourse();
void view_created_courses();
void view_enrolled_courses();
void view_details(string id);
void view_grades();
void view_grade_student();
void edit_details(course &c);
#endif
