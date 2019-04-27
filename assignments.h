#ifndef IUNI_ASSIGNMENTS_H
#define IUNI_ASSIGNMENTS_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "global_data.h"
using namespace std;

void upload_assignment();

bool view_assignment_list();

void download_assignment();

void remove_assignment();

void grade_assignment(string name);
#endif
