#include <iostream>
#include <fstream>
#include "global_data.h"
using namespace std;

bool addCourse(){
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
    this_user.courses.push_back(c.id);
    //Add course created by instructor in the text file
    string user_info = get_line_from_file(this_user.id, "UserInfo") + " " + c.id;
    edit_file(this_user.id,user_info,"UserInfo.txt");
    //Add course in a text file
    string courseInfo = c.id + " " + c.name + " " + c.des + " " + c.instructor.id + " " + c.instructor.lname + " " + c.instructor.fname;
    this_course = c;
    if (add_line_in_file(courseInfo,"CourseInfo.txt")){
        return true;
    }
    else{
        cout<<"Course cannot be created.\n";
        return false;
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

void view_created_courses(){
    if(this_user.courses.size() == 0)
    {
        cout<<"You have created no courses.\n";
        return;
    }
    cout<<"You created the following courses:\n";
    print_vector(this_user.courses);
}

void view_details(string id){
    cout<<get_line_from_file(id, "CourseInfo.txt");
}

void edit_details(course &c){
    while (true) {
        cout << "1 - Course Name:\t"<<c.name << '\n';
        cout << "2 - Course Description:\t"<< c.des << '\n';
        cout << "3 - Instructor First Name:\t"<< c.instructor.fname << '\n';
        cout << "4 - Instructor Last Name:\t"<<c.instructor.lname<<"\n";
        std::cout << "0 - Go Back" << '\n';
        cout << "Select the field you need to edit: ";
        int choice;
        cin>>choice;
        string name, des, fname, lname;
        switch (choice) {
            case 1:
                cout << "Enter new Course Name: ";
                cin>>c.name;
                break;
            case 2:
                cout << "Enter new Course Description: ";
                cin>>c.des;
                break;
            case 3:
                cout << "Enter new Instructor First Name: ";
                cin>>c.instructor.fname;
                break;
            case 4:
                cout << "Enter new Instructor Last Name: ";
                cin>>c.instructor.lname;
                break;
            case 0:
                return;
        }
        ifstream fin("CourseInfo.txt");
        ofstream fout("temp.txt");
        if (fin.is_open()) {
            std::string line;
            while (std::getline(fin, line)) {
                if(line.find(c.id+" ")==0){
                    fout<<c.id+" "+c.name+" "+c.des+" "+c.instructor.id+" "+c.instructor.fname+" "+c.instructor.lname<<"\n";
                }else{
                    fout<<line<<"\n";
                }
            }
            remove("CourseInfo.txt");
            rename("temp.txt", "CourseInfo.txt");
            fin.close();
            fout.close();
        } else {
            std::cerr << "Edit Failed\n";
        }
    }
}