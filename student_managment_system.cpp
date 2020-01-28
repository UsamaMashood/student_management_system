#include <iostream>
using namespace std;
#include<conio.h>
#include<fstream>
#include<string.h>
#include "clas_file.cpp"
#include "student_file.cpp"
#include "subject_file.cpp"
#include "result_file.cpp"


int main()
{
    int choice;
    while(1)
    {   
        system("cls");
        cout<<" 1) Class"<<endl;
        cout<<" 2) Student"<<endl;
        cout<<" 3) Subject"<<endl;
        cout<<" 4) Result"<<endl;
        cout<<" 5) Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        if (choice == 1)
            clas_menu();
        else if (choice == 2)
            student_menu();
        else if (choice == 3)
            subject_menu();
        else if (choice == 4)
            result_menu();
        else if (choice == 5)
            break;
        else
        {
            cout<<"invalid choice"<<endl;
            getch();
        }
    }
    return 0;
}