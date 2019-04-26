#include <iostream>
#include <fstream>
#include "global_data.h"
using namespace std;

void addCourse(){
    course c;
    cout<<"Enter Course ID";
    cin>>c.id;
    if(search_identifier(c.id, "CourseInfo.txt")){
    		cout<<"Course already exists.\n";
    		return;
    		//Add access to form option
    }
    cout<<"Enter Course Name";
    cin>>c.name;
    string courseInfo = c.id + " " + c.name;
    if (add_line_in_file(courseInfo,"CourseInfo.txt")){
        cout<<"Course was successfully created.\n";
        return;
    }
    else{
        cout<<"Course cannot be added.\n";
        return;
    }

}

