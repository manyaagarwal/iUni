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

bool view_assignment_list(string assignment[]){
    string filename = this_course.id + ".txt";
    ifstream fin(filename, std::ios::in);
    string line;
    getline(fin, line);
    int length = this_course.num_assignment;
    if(length == 0 ) return false;
    sstream ss(line+"\n");
    string temp;
    ss>>temp;
    for(int i=0; i<length; i++)
    {
        ss>>assignment[i];
        cout<<i+1<<". "<<assignment[i]<<endl;
    }
    return true;
}

void download_assignment(){
    int choice;
    string *assignment = new string[this_course.num_assignment];
    if (view_assignment_list(assignment)) {
        cout<<"Select assignment to download: ";
        cin>>choice;
        int index = choice - 1;
        string path;
        cout<<"Enter path to download: \n";
        getline(cin,path);
        string download = "download_assignment.sh" + " " + assignment[index] + " " + this_course.id + " " + path;
        system(download);
    } else {
        cout<<"This course has no downloads.\n";
    }

}
void delete_assigment(){

}

void grade_assignment(string name){
    string filename = this_course.id + ".txt";
    ifstream fin(filename, std::ios::in);
    ofstream fout(filename, std::ios::app);
    if (fin.is_open())
    {
        cout<<"Assignment does not exist.";
        return;
    }
    string line,name;
    string *course = new string[this_course.num_assignment];
    getline(fin,line);
    stringstream ss(line+"\n");
    ss>>name;
    for (int i=0; i<this_course.num_assignment; i++)
    {
        ss>>course[i];
        if(course[i] == name){
            break;
        }
    }
    int column = i;
    string grade;
    int pos;
    cout<<"Enter grades for the following students:\n";
    while(getline(ss,line))
    {
        ss>>name;
        cout<<name;
        for (int j = 0; j<i; j++)
        {
            ss>>course[j];
        }
        pos = ss.tellg();
        fout.seekp(pos+1);
        fout<<grade;
    }

}