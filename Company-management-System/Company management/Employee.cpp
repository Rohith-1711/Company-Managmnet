#include "Employee.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <iomanip>

using namespace std;

Employee::Employee()
{
    strcpy(pdetails.name," ");
    pdetails.empid = 0;                        //>=0
    strcpy(pdetails.aadhar," ");
    strcpy(pdetails.doj," ");
    pdetails.basic_sal=0;                      //>=0
    strcpy(pdetails.contact_no," ");
    strcpy(pdetails.dept," ");             //if (mobileNumber < 1000000000 || mobileNumber > 9999999999)
    strcpy(pdetails.desig,"");
    sdetails.no_of_present = 0;                 //>0
    sdetails.overtime = 0;                        //>=0
    sdetails.incentive = 0;                       //>0
}



void Employee::get_Data()
{
    cout<<"==========================================================";
    cout << "\n\t\t\t\t Personal details:\n";
    do
    {
	cout << "Enter employee id                  : ";
    cin >> pdetails.empid;
    fflush(stdin);
    if(pdetails.empid<=0)
    {
        cout << "\nInvalid employee id\n";
    }
    else if(check_id(pdetails.empid))
    {
        cout << "\nAlready an employee exists with same id.\n";
    }
    else
    break;
    }while(true);

    cout << "Enter name                         : ";
    gets(pdetails.name);

	cout<<"Enter aadhar card number             : ";
    gets(pdetails.aadhar);

    cout<<"Enter date of joining                : ";
    gets(pdetails.doj);
    do
    {
    cout<<"Enter basic salary                   : ";
    cin>>pdetails.basic_sal;fflush(stdin);
    if(pdetails.basic_sal>=0)
    break;
    else
    continue;
   }while(true);
   do
   {
    cout<<"Enter contact number                 : ";
    gets(pdetails.contact_no);
    if (strlen(pdetails.contact_no) == 10)
    break;
    else
    continue;
   }while(true);

    cout<<"Enter department                     : ";
    gets(pdetails.dept);

    cout<<"Enter designation                    : ";
    gets(pdetails.desig);

    cout<<"\n=========================================================";

    cout<<"\n SALARY DETAILS: ";
    do
    {
	cout<<"\nEnter attendance                   : ";
    cin>>sdetails.no_of_present;fflush(stdin);
    if(sdetails.no_of_present>=0)
    break;
    else
     continue;
    }while(true);
    do
    {
	cout<<"Enter overtime                       : ";
    cin>>sdetails.overtime;fflush(stdin);
    if(sdetails.overtime>=0)
    break;
    else
     continue;
    }while(true);
    do{
	cout<<"Enter incentive                      : ";
    cin>>sdetails.incentive;fflush(stdin);
    if(sdetails.incentive>=0)
    break;
    else
    continue;
    }while(true);

    cout<<"\n=========================================================";

}
void Employee::display_pdetails()
{
    cout<<"\n\t\t=====================================================";
    cout<<"\n\t\t\t\t PERSONAL DETAILS ";
    cout<<"\n\t\t\t EMPLOYEE ID        :"<<pdetails.empid;
    cout<<"\n\t\t\t NAME               :"<<pdetails.name;
    cout<<"\n\t\t\t AADHAR NO          :"<<pdetails.aadhar;
    cout<<"\n\t\t\t DATE OF JPOINING   :"<<pdetails.doj;
    cout<<"\n\t\t\t BASIC SALARY       :"<<pdetails.basic_sal;
    cout<<"\n\t\t\t CONTACT NUMBER     :"<<pdetails.contact_no;
    cout<<"\n\t\t\t DEPARTMENT         :"<<pdetails.dept;
    cout<<"\n\t\t\t DESIGNATION        :"<<pdetails.desig;
    cout<<"\n\t\t=====================================================";
}
void Employee::display_sdetails()
{
    cout<<"\n\n\n\t\t=====================================================";
    cout<<"\n\t\t\t\t SALARY DETAILS ";
    cout<<"\n\t\t\t ATTENDANCE         :"<<sdetails.no_of_present;
    cout<<"\n\t\t\t OVERTIME           :"<<sdetails.overtime;
    cout<<"\n\t\t\t INCENTIVE          :"<<sdetails.incentive;
    cout<<"\n\t\t=====================================================";
}

void Employee::displaydata()

{
    display_pdetails();
    display_sdetails();
}

void Employee::write()
{
    ofstream file("Employee.dat",ios::out|ios::app);
    file.write((char*)this,sizeof(Employee));
    file.close();
}

void Employee::displayfromfile()
{
    ifstream file("Employee.dat",ios::in);
    if(!file)
    {
        cout << "The file doesn't exist.";
        return;
    }
    Employee e;
    cout <<endl <<  std::setfill( '-' ) << std::setw( 84 ) << '-'
               << std::setfill(' ') << std::endl;
    cout  << "| " << setw(5) << left <<"EMPID" << "| " << setw(30) << left << "NAME" << "| " << setw(20) << left << "DEPARTMENT" << "| " << setw(20) << left << "DESIGNATION" << "|";
    cout << endl << std::setfill( '-' ) << std::setw( 84 )
              << '-';
    while(true)
    {
        file.read((char*)&e,sizeof(Employee));
        if(!file)
            break;
        else
            cout << endl << std::setfill(' ') << "| " << setw(5) << left <<e.pdetails.empid << "| "
            << setw(30) << left << e.pdetails.name << "| "
            << setw(20) << left << e.pdetails.dept << "| "
            << setw(20) << left << e.pdetails.desig << "|";
    }
    cout <<endl <<  std::setfill( '-' ) << std::setw( 84 ) << '-'<< std::setfill(' ')
               << std::endl;
    file.close();
}
int Employee::displayfromfile( char* name)
{
    ifstream file("Employee.dat",ios::in);
    Employee e;
    int count = 0;
    cout <<endl <<  std::setfill( '-' ) << std::setw( 84 ) << '-'
               << std::setfill(' ') << std::endl;
    cout  << "| " << setw(5) << left <<"EMPID" << "| " << setw(30) << left << "NAME" << "| " << setw(20) << left << "DEPARTMENT" << "| " << setw(20) << left << "DESIGNATION" << "|";
    cout << endl << std::setfill( '-' ) << std::setw( 84 )
              << '-';
    while(true)
    {
        file.read((char*)&e,sizeof(Employee));
        if(!file)
            break;
        else
            if(strstr(strupr(e.pdetails.name),strupr(name)))
            {cout << endl << std::setfill(' ') << "| " << setw(5) << left <<e.pdetails.empid << "| "
            << setw(30) << left << e.pdetails.name << "| "
            << setw(20) << left << e.pdetails.dept << "| "
            << setw(20) << left << e.pdetails.desig << "|";
            count++;}
    }
    cout <<endl <<  std::setfill( '-' ) << std::setw( 84 ) << '-'<< std::setfill(' ')
               << std::endl;
    file.close();
    return count;
}

void Employee::deletefile()
{
    remove("Employee.dat");
}

Employee Employee::findinfile()
{
    int id;
    int ch;
    char name[30];
    do
    {
        system("cls");
        Employee::displayfromfile();
        cout << "\n\n";
        cout << "1.Enter id\n";
        cout << "2.Find by name\n";
        cout << "3.Exit\n";
        cout << "Enter your choice:";
        cin >> ch;
        Employee e;
        e.pdetails.empid = -2;
        switch(ch)
        {
            case 2:
                    cout << "Enter the name:";
                    fflush(stdin);
                    gets(name);
                    if(Employee::displayfromfile(name)<1)
                    {
                        cout << "\n No record found.";
                        system("pause");
                        continue;
                    }
            case 1: cout << "Enter employee id:";
                    cin >> id;
            break;
            case 3: return e;
            default: continue;
        }
        ifstream file("Employee.dat",ios::in);
        while(true)
        {
            file.read((char*)&e,sizeof(Employee));
            if(!file)
                break;
            else
                if(e.pdetails.empid == id)
                return e;

        }
        file.close();
        e.pdetails.empid = -1;
        return e;
    }while(true);


}

void Employee::findanddisplayfromfile()
{
    Employee e;
    do {
    e = Employee::findinfile();
    if(e.pdetails.empid == -2)
        return;
    else if(e.pdetails.empid == -1)
    {
        cout << "\n Sorry No record found.\n";
    }
    else
        e.displaydata();
    cout << endl;
    system("pause");
    }while(true);
}
bool Employee::check_id(int id)
{
    Employee e;
    ifstream file("Employee.dat",ios::in);
    while(true)
    {
        file.read((char*)&e,sizeof(Employee));
        if(!file)
            break;
        else
            if(e.pdetails.empid == id)
            return true;

    }
    file.close();
    return false;
}

void Employee::deletefromdb()
{
    ifstream file("Employee.dat",ios::in);
    ofstream temp("temp.dat",ios::out);
    Employee e;
    while(true)
    {
        file.read((char*)&e,sizeof(Employee));
        if(!file)
            break;
        else
            if(e.pdetails.empid == pdetails.empid)
                continue;
        temp.write((char*)&e,sizeof(Employee));

    }
    file.close();
    temp.close();
    remove("Employee.dat");
    rename("temp.dat","Employee.dat");
}

long int Employee::getpos()
{
    ifstream file("Employee.dat",ios::in);
    Employee e;
    long int pos = -1;
    while(true)
    {
        file.read((char*)&e,sizeof(Employee));
        if(!file)
            break;
        else if(e.pdetails.empid == pdetails.empid)
            pos = (long int)file.tellg() - sizeof(Employee);
    }
    file.close();
    return pos;
}

void Employee::Modify()
{
    Employee e;
    do {
    e = Employee::findinfile();
    if(e.pdetails.empid == -2)
        return;
    else if(e.pdetails.empid == -1)
    {
        cout << "\n Sorry No record found.\n";
    }
    else
    {
        long int pos = e.getpos();
        e.modify_object();
        e.displaydata();
        fstream file("Employee.dat",ios::in|ios::out);
        cout << "\nPosition:" << pos;
        file.seekp(pos-1);
        cout << file.tellg();
        file.write((char*)&e,sizeof(e));
        e.displaydata();
        file.close();
        Employee e1;
         if(Employee::check_id(e.pdetails.empid))
            cout << "\nTrue";
    }
    cout << endl;
    system("pause");
    }while(true);
}

void Employee::modify_object()
{
    int exit1 = 0,exit2;
    int ch1,ch2;
    do
    {
        system("cls");
        cout << "Modify\n";
        cout << "1.Personal details\n";
        cout << "2.Salary details\n";
        cout << "3.Exit\n";
        cout << "Enter your choice:";
        cin >> ch1;
        system("cls");
        exit2 = 0;
        switch(ch1)
        {
        case 1:
            {
                do
                {
                    system("cls");
                    display_pdetails();
                    cout << endl;
                    cout << "Modify\n";
                    cout << "1.Employee id\n";
                    cout << "2.Name\n";
                    cout << "3.Aadhaar\n";
                    cout << "4.Date of Joining\n";
                    cout << "5.Basic salary\n";
                    cout << "6.Contact number\n";
                    cout << "7.Department\n";
                    cout << "8.Designation\n";
                    cout << "9.Exit\n";
                    cout << "Enter your choice:";
                    cin >> ch2;
                    switch(ch2)
                    {
                        case 1:
                        do
                        {
                        cout << "Enter new employee id : ";
                        cin >> pdetails.empid;
                        fflush(stdin);
                        if(pdetails.empid<=0)
                        {
                            cout << "\nInvalid employee id\n";
                        }
                        else if(check_id(pdetails.empid))
                        {
                            cout << "\nAlready an employee exists with same id.\n";
                        }
                        else
                        break;
                        }while(true);
                        break;

                        case 2:
                        cout << "Enter new name: ";
                        fflush(stdin);
                        gets(pdetails.name);
                        break;

                        case 3:
                        cout<<"Enter new aadhar card number: ";
                        fflush(stdin);
                        gets(pdetails.aadhar);
                        break;

                        case 4:
                        cout<<"Enter new date of joining: ";
                        fflush(stdin);
                        gets(pdetails.doj);
                        break;

                        case 5:
                        do
                        {
                        cout<<"Enter new basic salary: ";
                        cin>>pdetails.basic_sal;fflush(stdin);
                        if(pdetails.basic_sal>=0)
                        break;
                        else
                        continue;
                       }while(true);
                       break;

                       case 6:
                       do
                       {
                        cout<<"Enter new contact number: ";
                        fflush(stdin);
                        gets(pdetails.contact_no);
                        if (strlen(pdetails.contact_no) == 10)
                        break;
                        else
                        continue;
                       }while(true);
                       break;

                       case 7:
                       cout<<"Enter new department: ";
                       fflush(stdin);
                       gets(pdetails.dept);
                       break;

                       case 8:
                       cout<<"Enter new designation: ";
                       fflush(stdin);
                       gets(pdetails.desig);
                       break;

                       case 9: exit2 = 1;
                    }
                }while(exit2 == 0);

            }
            break;

            case 2:
            {
               do
                {
                    system("cls");
                    display_sdetails();
                    cout << endl;
                    cout << "Modify\n";
                    cout << "1.No of present\n";
                    cout << "2.Overtime\n";
                    cout << "3.Incentive\n";
                    cout << "4.Exit\n";
                    cout << "Enter your choice:";
                    cin >> ch2;
                    switch(ch2)
                    {
                       case 1:
                       do
                        {
                        cout<<"\nEnter new attendance: ";
                        cin>>sdetails.no_of_present;fflush(stdin);
                        if(sdetails.no_of_present>=0)
                        break;
                        else
                         continue;
                        }while(true);
                        break;

                        case 2:
                        do
                        {
                        cout<<"Enter overtime: ";
                        cin>>sdetails.overtime;fflush(stdin);
                        if(sdetails.overtime>=0)
                        break;
                        else
                         continue;
                        }while(true);
                        break;

                        case 3:
                        do{
                        cout<<"Enter incentive: ";
                        cin>>sdetails.incentive;fflush(stdin);
                        if(sdetails.incentive>=0)
                        break;
                        else
                        continue;
                        }while(true);
                        break;

                        case 4: exit2 = 1;
                        break;
                    }
                }while(exit2 == 0);
            }
            break;

            case 3: exit1 = 1;
        }
    }while(exit1 == 0);
}

void Employee::Delete()
{
    Employee e = Employee::findinfile();
    e.deletefromdb();
}
char* Employee::classname()
{
    return "Employee";
}





