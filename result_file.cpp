
struct result
{
    int clas_id;
    int rollno;
    int subject_id;
    float marks;
};


int check_data(int clas_id, int rollno, int subject_id)
{
    subject sb;
    ifstream ifs("subject.bin");
    int check = 0;
    while(ifs.read(reinterpret_cast<char*>(&sb), sizeof(sb)))
    {
        if (clas_id == sb.clas_id && subject_id == sb.subject_id)
            check=1;
    }
    ifs.close();
    if (check)
    {
        student s;
        ifstream ifs2("student.bin");
        while(ifs2.read(reinterpret_cast<char*>(&s), sizeof(s)))
        {
            if (clas_id == s.clas_id && rollno == s.rollno)
                check=2;   
        }
        ifs2.close();
    }
    return check;
}


void add_result()
{
    

    system("cls");
    result r;
    ofstream ofs("result.bin", ios_base::app);
    cout << "Enter class id, rollno, subject id and marks" << endl;
    cout << "Enter Class id : ";
    cin >> r.clas_id;
    cout << "Enter Roll no : ";
    cin >> r.rollno;
    cout << "Enter Subject id : ";
    cin >> r.subject_id;
    cout << "Enter Marks : ";
    cin >> r.marks;
    int check = check_data(r.clas_id, r.rollno, r.subject_id);
    if (check==2)
    {
        ofs.write(reinterpret_cast<char *>(&r), sizeof(r));
        cout << "Student Data Enter succfully." << endl;
    }
    else
        cout << "No such data exist" << endl;
    ofs.close();
    getch();
}


void search_result(int choice)
{
    system("cls");
    result r;
    ifstream ifs("result.bin");
    if (choice==1)
    {
        int clas_id;
        cout<<"Enter class id : ";
        cin>>clas_id;
        system("cls");
        cout << "Class_id\tRollno\tSubject ID\t Marks" << endl;
        while (ifs.read(reinterpret_cast<char *>(&r), sizeof(r)))
        {
            if (clas_id==r.clas_id)
            {
                cout << r.clas_id << "\t\t" << r.rollno << "\t"<<r.subject_id<<"\t\t" << r.marks << endl;
            }
        }
    }
    else
    {
        int clas_id, rollno;
        cout<<"Enter class id : ";
        cin>>clas_id;
        cout<<"Enter roll no : ";
        cin>>rollno;
        system("cls");
        cout << "Class_id\tRollno\tSubject ID\t Marks" << endl;
        float sum =0;
        while (ifs.read(reinterpret_cast<char *>(&r), sizeof(r)))
        {
            if (clas_id==r.clas_id && rollno == r.rollno)
            {
                cout << r.clas_id << "\t\t" << r.rollno << "\t"<<r.subject_id<<"\t\t" << r.marks << endl;
                sum += r.marks;
            }
        }
        if (sum !=0)
            cout<<"total = "<<sum<<endl;
    }
    getch();
    ifs.close();
}



void search_result_menu()
{
    int choice;
    while(1)
    {   
        system("cls");
        cout<<" 1) Search by Class id"<<endl;
        cout<<" 2) search by Calss id and Rollno"<<endl;;
        cout<<" 3) Back To Result Menu"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        if (choice == 1 || choice == 2)
            search_result(choice);     
        else if (choice == 3) 
           break;
        else
        {
            cout<<"invalid choice"<<endl;
            getch();
        }

    }

}



void result_menu()
{
    int choice;
    while(1)
    {   
        system("cls");
        cout<<" 1) Add Result"<<endl;
        cout<<" 2) Search result"<<endl;
        cout<<" 3) Back To Main Menu"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        if (choice == 1)
            add_result();
        else if (choice == 2)
            search_result_menu();
        else if (choice == 3) 
           break;
        else
        {
            cout<<"invalid choice"<<endl;
            getch();
        }
    }
}
