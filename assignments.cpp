void upload_assignment()
{
    string path;
    string filename;
    cout<<"Enter the filename:\n";
    cin>>filename;
    cout<<"Enter the destination of the assignment on your system:\n";
    getline(cin,path);
    string cmd = "./upload.sh " + filename + " " + path + " " + this_course.id;
    system(cmd.c_str());
    this_course.num_assignment++;
    sstream ss(line+"\n");
    string courseFile = this_course.id + ".txt";
    ifstream fin(courseFile);
    string courseInfo;
    getline(fin, courseInfo);
    //Updating course info in the individual text file
    courseInfo += this_course.id + " ";
    edit_file("Name ", courseInfo, courseFile);
    //Updating the assignment count in the CourseInfo text file
    string assignmentCount = this_course.id + " " + this_course.name + " " + this_course.des + " " + this_course.instructor.id + " "
            + this_course.instructor.lname + " " + this_course.instructor.fname + " " + to_string(this_course.num_assignment);
    edit_file(this_course.id, assignmentCount, "CourseInfo.txt");
}
void download_assignment(){

}
void delete_assigment(){

}

void grade_assignment(string name){
    ifstream fin(name, std::ios::in);
    if (fin.is_open())
    {
        cout<<"Assignment does not exist.";
        return;
    }
    string line,name;
    string *course = new string[this_course.num_assignment];
    getline(fin,line);
    stringstream ss(line+"\n");
    ss>name;
    for (int i=0; i<this_course.num_assignment; i++)
    {
        ss>course[i];
        if(course[i] == name){
            break;
        }
    }
    cout<<i;

}