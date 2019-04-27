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
    getline(cin, c.name);
    cout<<"Enter Course Name: ";
    getline(cin, c.name);
    cout<<"Add Course Description: ";
    getline(cin, c.des);
    c.instructor = this_user;
    string courseInfo = c.id + " " + c.name + " " + c.des + " " + c.instructor.id + " " + c.instructor.lname + " " + c.instructor.fname;
    if (add_line_in_file(courseInfo,"CourseInfo.txt")){
        cout<<"Course was successfully created.\n";
        return;
    }
    else{
        cout<<"Course cannot be created.\n";
        return;
    }
}

void enrollCourse() {
    course c;
    char choice;
    cout<<"Enter Course Code to Enroll: ";
    cin>>c.id;

    if (!search_identifier(c.id,"CourseInfo.txt"))
    {
        cout<<"Course Code that you entered does not exist.";
        return;
    }
    string course = get_line_from_file(c.id,"CourseInfo.txt");
    printf("Course details are as follows:\n%s\n", course.c_str());
    cout<<"Do you want to confirm enrolling in this course? (Y/N) ";
    cin>> choice;
    if (choice == 'Y')
    {
        string line;
        string course_file = c.id + ".txt";
        bool add_header = false;
        ifstream fin(course_file, std::ios::in);
        if (!fin.is_open()){
            add_header = true;
        }
        fin.close();
        ofstream fout(course_file, std::ios::app);
        if (add_header) fout<<"Student ID \n";
        this_user.courses.push_back(c.id);
        fout<<this_user.id<<endl;
        string user_info = get_line_from_file(this_user.id, "UserInfo") + " " + c.id;
        edit_file(this_user.id,user_info,"UserInfo.txt");
        fout.close();
    }
}

void view_enrolled_courses(){
    if (this_user.courses.size() == 0)
    {
        cout<<"You are enrolled in no courses.\n";
        return;
    }
    cout<<"You are enrolled in the following courses:\n";
    print_vector(this_user.courses);
}

