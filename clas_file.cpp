
struct clas
{
    int clas_id;
    char clas_name[30];
};


int check_clas_id(int clas_id)
{
    // add te entry into array
    clas c;
    int check = 0;
    ifstream ifs("clas.bin");
    while (ifs.read(reinterpret_cast<char *>(&c), sizeof(c)))
    {
        if (c.clas_id == clas_id)
            check = 1;
    }
    return check;
}


void move_temp_clas()
{
    clas c;
    ifstream ifs("temp.bin");
    ofstream ofs("clas.bin");
    while (ifs.read(reinterpret_cast<char *>(&c), sizeof(c)))
        ofs.write(reinterpret_cast<char *>(&c), sizeof(c));
    ifs.close();
    ofs.close();
    system("rm temp.bin");
}


void add_clas()
{
    system("cls");
    clas c;
    // add data to file
    ofstream ofs("clas.bin", ios_base::app);
    cout << "Enter class id, class name " << endl;
    cout << "Enter class id : ";
    cin >> c.clas_id;
    cout << "Enter class name : ";
    cin >> c.clas_name;
    int check = check_clas_id(c.clas_id);
    if (check)
        cout << "class id already exist. " << endl;
    else
    {
        ofs.write(reinterpret_cast<char *>(&c), sizeof(c));
        cout << "Data enter successfully" << endl;
    }
    ofs.close();
}


void display_clas()
{
    system("cls");
    clas c;
    // Display all the entry
    cout << "Id\tName" << endl;
    ifstream ifs("clas.bin");
    while (ifs.read(reinterpret_cast<char *>(&c), sizeof(c)))
        cout << c.clas_id << "\t" << c.clas_name << endl;
    ifs.close();
}


void modify_clas()
{
    system("cls");
    clas c;
    int id;
    cout << "Enter te class id of clas whose data to modify : ";
    cin >> id;
    // move data after delete to temp.bin from clas.bin
    ifstream ifs("clas.bin");
    ofstream ofs("temp.bin");
    int check = 1;
    int check_2 = 1;
    while (ifs.read(reinterpret_cast<char *>(&c), sizeof(c)))
    {
        if (id == c.clas_id)
        {
            while(check_2)
            {
                cout << "Enter class id, class name" << endl;
                cout << "Enter id : ";
                cin >> c.clas_id;
                cout << "Enter clas clas_name : ";
                cin >> c.clas_name;
                check = 0;
                check_2 = check_clas_id(c.clas_id);
                if (check_2 && c.clas_id ==id )
                    break;
                cout<<"clas id already exist"<<endl;
            }
        }
        ofs.write(reinterpret_cast<char *>(&c), sizeof(c));
    }
    ifs.close();
    ofs.close();
    // move data back to clas.bin file
    move_temp_clas();
    if (check)
        cout << "NO, such class id exist" << endl;
    else
        cout << "Entry update successfully" << endl;
}


void delete_clas()
{
    system("cls");
    clas c;
    int id;
    cout << "Enter te clas_id of clas whose data to delete : ";
    cin >> id;
    // move data after modify to temp.bin from clas.bin
    ifstream ifs("clas.bin");
    ofstream ofs("temp.bin");
    int check = 1;
    while (ifs.read(reinterpret_cast<char *>(&c), sizeof(c)))
    {
        if (id != c.clas_id)
            ofs.write(reinterpret_cast<char *>(&c), sizeof(c));
        else
            check = 0;
    }
    ifs.close();
    ofs.close();
    // move data back to clas.bin file
    move_temp_clas();
    if (check)
        cout << "NO, such clas_id exist" << endl;
    else
        cout << "Entry Delete successfully" << endl;

}


void clas_menu()
{
    int choice;
    while(1)
    {   
        system("cls");
        cout<<" 1) Add Class"<<endl;
        cout<<" 2) Display Class"<<endl;
        cout<<" 3) Modify Class"<<endl;
        cout<<" 4) Delete Class"<<endl;
        cout<<" 5) Back To Main Menu"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        if (choice == 1)
            add_clas();   
        else if (choice == 2)
           display_clas();
        else if (choice == 3)
           modify_clas();
        else if (choice == 4)
           delete_clas();
        else if (choice == 5) 
           break;
        else
           cout<<"invalid choice"<<endl;
        getch();
    }

}
