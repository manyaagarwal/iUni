#include <iostream>
#include <fstream>
#include "global_data.h"
using namespace std;

void addCourse(){
    course c;
    cout<<"Enter Course Code: ";
    cin>>c.id;
    if(search_identifier(c.id, "CourseInfo.txt")){
    		cout<<"Course already exists.\n";
    		return;
    		//Add access to form option
    }
    cout<<"Enter Course Name: ";
    cin>>c.name;
    cout<<"Add Course Description: ";
    cin>>c.des;
    c.instructor = this_user;
    string courseInfo = c.id + " " + c.name + " " + c.des + " " + c.instructor;
    if (add_line_in_file(courseInfo,"CourseInfo.txt")){
        cout<<"Course was successfully created.\n";
        return;
    }
    else{
        cout<<"Course cannot be added.\n";
        return;
    }
}

