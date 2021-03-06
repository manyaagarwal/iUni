#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "global_data.h"
#include <sstream>
#include <cstdlib>
using namespace std;

void upload_assignment()
{
    string path;
    string filename;
    cout<<"Enter the filename:\n";
    cin>>filename;
    cout<<"Enter the destination of the assignment on your system:\n";
    getline(cin,path);
    getline(cin,path);
    string cmd = "./upload.sh " + filename + " " + path + " " + this_course.id;
    system(cmd.c_str());
    get_course_info(this_course.id, this_course);
    this_course.num_assignment++;
    string courseFile = this_course.id + ".txt";
    ifstream fin(courseFile);
    string courseInfo;
    getline(fin, courseInfo);
    //Updating course info in the individual text file
    string line;
    if(!getline(fin,line))
    {
        courseInfo = "Name " + filename;
        add_line_in_file(courseInfo,courseFile);
    }
    else {
        courseInfo += filename + " ";
        edit_file("Name ", courseInfo, courseFile);
    }
    //Updating the assignment count in the CourseInfo text file
    string assignmentCount = this_course.id + "\t" + this_course.name + "\t" + this_course.des + "\t" + this_course.instructor.id + "\t"
            + this_course.instructor.lname + "\t" + this_course.instructor.fname + "\t" + to_string(this_course.num_assignment);
    edit_file(this_course.id, assignmentCount, "CourseInfo.txt");
}

bool view_assignment_list(string assignment[]){
    string filename = this_course.id + ".txt";
    ifstream fin(filename, std::ios::in);
    string line;
    getline(fin, line);
    int length = this_course.num_assignment;
    if(length == 0 ) return false;
    stringstream ss(line+"\n");
    string temp;
    ss>>temp;
    for(int i=0; i<length; i++)
    {
        ss>>assignment[i];
        cout<<i+1<<". "<<assignment[i]<<endl;
    }
    return true;
}

void download_assignment(string id){
    int choice;
    string *assignment = new string[this_course.num_assignment];
    get_course_info(id, this_course);
    if (view_assignment_list(assignment)) {
        cout<<"Select assignment to download: ";
        cin>>choice;
        int index = choice - 1;
        string path;
        cout<<"Enter path to download: \n";
        getline(cin,path);
        string assignment_name = assignment[index];
        string download = "./download_assignment.sh" " " + assignment_name + " " + this_course.id + " " + path;
        system(download.c_str());
    } else {
        cout<<"This course has no assignments.\n";
    }

}
void remove_assignment(){
    int choice;
    string *assignment = new string[this_course.num_assignment];
    if (view_assignment_list(assignment)){
         cout<<"Select assignment to delete: ";
         cin>>choice;
         int index = choice - 1;
         string course_file = this_course.id + ".txt";
         fstream fin(course_file);
         string line;
         string name;
         getline(fin,line);
         stringstream ss(line+"\n");
         ss>>name;
         string newline;
         newline += name;
         int column;
         for (int i=0; i<this_course.num_assignment; i++) {
             ss>>assignment[i];
             if(assignment[i] == name){
                 column = i+2;
             }
             else {
                 newline += " " + assignment[i];
             }
         }
         edit_file("Name ", newline, course_file);

         string del = "./delete.sh " " " + assignment[index] + " " + this_course.id;  //To delete file from course directoru
         string file = this_course.id+".txt";
         string del_column = "awk '{$" + to_string(column) + "=\"\"; print $0}' " + file + " > temp.txt";
         system(del.c_str());
         system(del_column.c_str());  //To delete assignment column from course txt
         remove(file.c_str());
         rename("text.txt", file.c_str());


    }

}

void grade_assignment(string name){
    string filename = this_course.id + ".txt";
    ifstream fin(filename, std::ios::in);
    ofstream fout(filename, std::ios::app);
    if (!fin.is_open())
    {
        cout<<"Assignment does not exist.";
        return;
    }
    string line;
    string nameS;
    string *course = new string[this_course.num_assignment];
    getline(fin,line);
    stringstream ss(line+"\n");
    ss>>nameS;
    int column;
    for (int i=0; i<this_course.num_assignment; i++)
    {
        ss>>course[i];
        if(course[i] == name){
            column = i;
        }
    }
    string grade;
    int pos;
    cout<<"Enter grades for the following students:\n";
    int counter = 1;
    while(getline(fin,line))
    {
        ss = stringstream(line+"\n");
        ss>>nameS;
        cout<<nameS;
        cin>>grade;
        for (int j = 0; j<column; j++)
        {
            ss>>course[j];
        }
        pos =  (line.size() * counter) + ss.tellg();
        fout.seekp(pos+1);
        fout<<grade;
        counter++;
    }

}
