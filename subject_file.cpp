struct subject
{
    int clas_id;
    int subject_id;
    char subject_name[30];
};


int check_subject_id(int subject_id)
{
    subject sb;
    int check=0;
    ifstream ifs("subject.bin");
    while (ifs.read(reinterpret_cast<char *>(&sb), sizeof(sb)))
    {
        if (subject_id == sb.subject_id)
            check = 1;
    }
    return check;
}


void move_temp_subject()
{
    subject sb;
    ifstream ifs("temp.bin");
    ofstream ofs("subject.bin");
    while (ifs.read(reinterpret_cast<char *>(&sb), sizeof(sb)))
        ofs.write(reinterpret_cast<char *>(&sb), sizeof(sb));
    ifs.close();
    ofs.close();
    system("rm temp.bin");
}


void add_subject()
{
    system("cls");
    subject sb;
    ofstream ofs("subject.bin", ios_base::app);
    cout << "Enter class id, subject id and subject name" << endl;
    cout << "Enter Class id : ";
    cin >> sb.clas_id;
    cout << "Enter Subject id : ";
    cin >> sb.subject_id;
    cout << "Enter Subject name : ";
    cin >> sb.subject_name;
 
    if (check_clas_id(sb.clas_id))
    {
        if ( check_subject_id(sb.subject_id))
            cout<<"roll no already given"<<endl;
        else
        {            
            ofs.write(reinterpret_cast<char *>(&sb), sizeof(sb));
            cout << "Student Data Enter succfully." << endl;
        }
    }
    else
        cout << "Class id does not exist first add Class." << endl;
}


void delete_subject()
{
    system("cls");
    subject sb;
    int subject_id, clas_id;
    cout << "Enter subject id whose data to delete : ";
    cin >> subject_id;
    cout << "Enter class id whose data to delete : ";
    cin >> clas_id;
    ifstream ifs("subject.bin");
    ofstream ofs("temp.bin");
    int check = 1;
    while (ifs.read(reinterpret_cast<char *>(&sb), sizeof(sb)))
    {
        if (subject_id == sb.subject_id && clas_id == sb.clas_id )
            check = 0;
        else
            ofs.write(reinterpret_cast<char *>(&sb), sizeof(sb));
    }
    ifs.close();
    ofs.close();
    // move data back to student.bin file
    move_temp_subject();
    if (check)
        cout << "NO, such class id and subject_id data exist" << endl;
    else
        cout << "Entry Delete successfully" << endl;
    getch();
}

void display_subject()
{
    system("cls");
    subject sb;
    // Display all the entry
    cout << "Class Id\tSubject Id\tName" << endl;
    ifstream ifs("subject.bin");
    while (ifs.read(reinterpret_cast<char *>(&sb), sizeof(sb)))
        cout << sb.clas_id << "\t\t" << sb.subject_id << "\t\t" << sb.subject_name << endl;
    ifs.close();
}

void subject_menu()
{
    int choice;
    while(1)
    {   
        system("cls");
        cout<<" 1) Add Suject"<<endl;
        cout<<" 2) Delete Subject"<<endl;
        cout<<" 3) Display Subject"<< endl;
        cout<<" 4) Back To Main Menu"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        if (choice == 1)
            add_subject();
        else if (choice == 2)
            delete_subject();
        else if (choice == 3) 
           display_subject();
        else if (choice == 4) 
           break;
        else
           cout<<"invalid choice"<<endl;
        getch();
    }

}