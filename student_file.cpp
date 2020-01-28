
struct student
{
    int clas_id;
    int rollno;
    char student_name[30];
};


int check_student_rollno(int rollno)
{
    student s;
    int check=0;
    ifstream ifs("student.bin");
    while (ifs.read(reinterpret_cast<char *>(&s), sizeof(s)))
    {
        if (rollno == s.rollno)
            check=1;
    }
    ifs.close();
    return check;
}


void move_temp_student()
{
    student s;
    ifstream ifs("temp.bin");
    ofstream ofs("student.bin");
    while (ifs.read(reinterpret_cast<char *>(&s), sizeof(s)))
        ofs.write(reinterpret_cast<char *>(&s), sizeof(s));
    ifs.close();
    ofs.close();
    system("rm temp.bin");
}




void add_student()
{
    system("cls");
    student s;
    ofstream ofs("student.bin", ios_base::app);
    cout << "Enter class id, roll no and student name" << endl;
    cout << "Enter Class id : ";
    cin >> s.clas_id;
    cout << "Enter Student roll no : ";
    cin >> s.rollno;
    cout << "Enter student name : ";
    cin >> s.student_name;
    if (check_clas_id(s.clas_id))
    {
        if ( check_student_rollno(s.rollno))
            cout<<"roll no already given"<<endl;
        else
        {            
            ofs.write(reinterpret_cast<char *>(&s), sizeof(s));
            cout << "Student Data Enter succfully." << endl;
        }
    }
    else
        cout << "Class id does not exist first add Class." << endl;
    getch();
}

void search_student(int rollno,char name[30])
{
    system("cls");
    student s;
    // Display all the entry
    cout << "Class Id\tRollno\tName" << endl;
    ifstream ifs("student.bin");
    while (ifs.read(reinterpret_cast<char *>(&s), sizeof(s)))
    {
        if (rollno !=0)
        {
            if (rollno == s.rollno)
                cout<< s.clas_id << "\t" << s.rollno << "\t" << s.student_name << endl;
        }
        else
        {
            if (strcmp(name,s.student_name)==0)
                cout << s.clas_id << "\t" << s.rollno << "\t" << s.student_name << endl;
        } 
    }
    ifs.close();
}

void search_student_menu()
{
    int choice;
    while(1)
    {   
        system("cls");
        cout<<" 1) Search by Rollno"<<endl;
        cout<<" 2) search by Name"<<endl;;
        cout<<" 3) Back To Student Menu"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        if (choice == 1)
        {
            int rollno;
            cout<<"Enter roll no :";
            cin>>rollno;
            char temp[30] = "~121";
            search_student(rollno,temp);
            getch();

        }
        else if (choice == 2)
        {
            char name[30];
            cout<<"Enter name :";
            cin>>name;
            search_student(0, name);
            getch();
        }        
        else if (choice == 3) 
           break;
        else
        {
            cout<<"invalid choice"<<endl;
            getch();
        }

    }
    
}

void modify_student()
{
    system("cls");
    student s;
    int rollno, clas_id;
    cout << "Enter te student roll whose data to modify : ";
    cin >> rollno;
    cout<< "Enter class id of student of whose data to modify : ";
    cin>> clas_id;
    ifstream ifs("student.bin");
    ofstream ofs("temp.bin");
    int check = 1;
    while (ifs.read(reinterpret_cast<char *>(&s), sizeof(s)))
    {
        if (rollno == s.rollno && clas_id  == s.clas_id)
        {

            while(1)
            {
                system("cls");
                cout << "Enter class id, class name" << endl;
                cout << "Enter class id : ";
                cin >> s.clas_id;
                cout << "Enter student roll no : ";
                cin >> s.rollno;
                cout << "Enter student name : ";
                cin >> s.student_name;
                check = 0;
                if (check_clas_id(s.clas_id))
                {
                    if (check_student_rollno(s.rollno)==0 || s.rollno ==rollno)
                    {
                        cout << "Entry update successfully" << endl;
                        break;
                    }
                    else
                        cout<<"Roll no already exist"<<endl;    
                }
                else
                    cout<<"No, such class id exist first add class"<<endl;
                getch();
            }
        }
        ofs.write(reinterpret_cast<char *>(&s), sizeof(s));
    }
    ifs.close();
    ofs.close();
    if (check)
        cout<<"NO data of that roll number and class id"<<endl;
    // move data back to student.bin file
    move_temp_student();
    getch();
}

void delete_student()
{
    system("cls");
    student s;
    int rollno, clas_id;
    cout << "Enter studnet rollno of student whose data to delete : ";
    cin >> rollno;
    cout << "Enter class id whose data to delete : ";
    cin >> clas_id;
    ifstream ifs("student.bin");
    ofstream ofs("temp.bin");
    int check = 1;
    while (ifs.read(reinterpret_cast<char *>(&s), sizeof(s)))
    {
        if (rollno == s.rollno && clas_id == s.clas_id )
            check = 0;
        else
            ofs.write(reinterpret_cast<char *>(&s), sizeof(s));
    }
    ifs.close();
    ofs.close();
    // move data back to student.bin file
    move_temp_student();
    if (check)
        cout << "NO, such class id and rollno data exist" << endl;
    else
        cout << "Entry Delete successfully" << endl;
    getch();
}

void student_menu()
{
    int choice;
    while(1)
    {   
        system("cls");
        cout<<" 1) Add student"<<endl;
        cout<<" 2) Search student"<<endl;
        cout<<" 3) Modify student"<<endl;
        cout<<" 4) Delete student"<<endl;
        cout<<" 5) Back To Main Menu"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        if (choice == 1)
            add_student();
        else if (choice == 2)
            search_student_menu();
        else if (choice == 3)
            modify_student();
        else if (choice == 4)
            delete_student();
        else if (choice == 5) 
           break;
        else
        {
           cout<<"invalid choice"<<endl;
           getch();
        }
    }

}
