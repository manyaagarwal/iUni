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
    string courseFile = this_course.id + ".txt";
    ifstream fin(courseFile);
    string courseInfo;
    getline(fin, courseInfo);
    courseInfo += this_course.id + " ";
    edit_file("Name ", courseInfo, courseFile);
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