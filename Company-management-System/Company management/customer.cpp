#include "customer.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <iomanip>

using namespace std;

Customer::Customer()
{
    custid = 0;
    strcpy(name," ");
    strcpy(phno," ");
}



void Customer::get_Data()
{
    cout<<"==========================================================";
    cout << "\n\t\t\t\t Enter Customer details:\n";
    do
    {
	cout << "Enter customer id                  : ";
    cin >> custid;
    fflush(stdin);
    if(custid<=0)
    {
        cout << "\nInvalid customer id\n";
    }
    else if(check_id(custid))
    {
        cout << "\nAlready an customer exists with same id.\n";
    }
    else
    break;
    }while(true);

    cout << "Enter name                         : ";
    gets(name);
   do
   {
    cout<<"Enter contact number                 : ";
    gets(phno);
    if (strlen(phno) == 10)
    break;
    else
    continue;
   }while(true);

    cout<<"\n=========================================================" << endl;

}

void Customer::displaydata()

{
    cout<<"\n\t\t=====================================================";
    cout<<"\n\t\t\t\t Customer DETAILS ";
    cout<<"\n\t\t\t CUSTOMER ID        :"<<custid;
    cout<<"\n\t\t\t NAME               :"<<name;
    cout<<"\n\t\t\t CONTACT NUMBER     :"<<phno;
    cout<<"\n\t\t=====================================================";
}

void Customer::write()
{
    ofstream file("Customer.dat",ios::out|ios::app);
    file.write((char*)this,sizeof(Customer));
    file.close();
}

void Customer::displayfromfile()
{
    ifstream file("Customer.dat",ios::in);
    if(!file)
    {
        cout << "The file doesn't exist.";
        return;
    }
    Customer e;
    cout <<endl <<  std::setfill( '-' ) << std::setw( 62 ) << '-'
               << std::setfill(' ') << std::endl;
    cout  << "| " << setw(5) << left <<"ID" << "| " << setw(30) << left << "NAME" << "| " << setw(20) << left << "PHONE NUMBER" << "| " ;
    cout << endl << std::setfill( '-' ) << std::setw( 62 )
              << '-';
    while(true)
    {
        file.read((char*)&e,sizeof(Customer));
        if(!file)
            break;
        else
            cout << endl << std::setfill(' ') << "| " << setw(5) << left <<e.custid << "| "
            << setw(30) << left << e.name << "| "
            << setw(20) << left << e.phno << "| ";
    }
    cout <<endl <<  std::setfill( '-' ) << std::setw( 62 ) << '-'<< std::setfill(' ')
               << std::endl;
    file.close();
}
int Customer::displayfromfile( char* name)
{
    ifstream file("Customer.dat",ios::in);
    Customer e;
    int count = 0;
    cout <<endl <<  std::setfill( '-' ) << std::setw( 62 ) << '-'
               << std::setfill(' ') << std::endl;
    cout  << "| " << setw(5) << left <<"ID" << "| " << setw(30) << left << "NAME" << "| " << setw(20) << left << "PHONE NUMBER" << "| " ;
    cout << endl << std::setfill( '-' ) << std::setw( 62 )
              << '-';
    while(true)
    {
        file.read((char*)&e,sizeof(Customer));
        if(!file)
            break;
        else
            if(strstr(strupr(e.name),strupr(name)))
            { cout << endl << std::setfill(' ') << "| " << setw(5) << left <<e.custid << "| "
            << setw(30) << left << e.name << "| "
            << setw(20) << left << e.phno << "| ";
            count++;}
    }
   cout <<endl <<  std::setfill( '-' ) << std::setw( 62 ) << '-'<< std::setfill(' ')
               << std::endl;
    file.close();
    return count;
}

void Customer::deletefile()
{
    remove("Customer.dat");
}

Customer Customer::findinfile()
{
    int id;
    int ch;
    char name[30];
    do
    {
        system("cls");
        Customer::displayfromfile();
        cout << "\n\n";
        cout << "1.Enter id\n";
        cout << "2.Find by name\n";
        cout << "3.Exit\n";
        cout << "Enter your choice:";
        cin >> ch;
        Customer e;
        e.custid = -2;
        switch(ch)
        {
            case 2:
                    cout << "Enter the name:";
                    fflush(stdin);
                    gets(name);
                    if(Customer::displayfromfile(name)<1)
                    {
                        cout << "\n No record found.";
                        system("pause");
                        continue;
                    }
            case 1: cout << "Enter customer id:";
                    cin >> id;
            break;
            case 3: return e;
            default: continue;
        }
        ifstream file("Customer.dat",ios::in);
        while(true)
        {
            file.read((char*)&e,sizeof(Customer));
            if(!file)
                break;
            else
                if(e.custid == id)
                return e;

        }
        file.close();
        e.custid = -1;
        return e;
    }while(true);


}

void Customer::findanddisplayfromfile()
{
    Customer e;
    do {
    e = Customer::findinfile();
    if(e.custid == -2)
        return;
    else if(e.custid == -1)
    {
        cout << "\n Sorry No record found.\n";
    }
    else
        e.displaydata();
    cout << endl;
    system("pause");
    }while(true);
}
bool Customer::check_id(int id)
{
    Customer e;
    ifstream file("Customer.dat",ios::in);
    while(true)
    {
        file.read((char*)&e,sizeof(Customer));
        if(!file)
            break;
        else
            if(e.custid == id)
            return true;

    }
    file.close();
    return false;
}

void Customer::deletefromdb()
{
    ifstream file("Customer.dat",ios::in);
    ofstream temp("temp.dat",ios::out);
    Customer e;
    while(true)
    {
        file.read((char*)&e,sizeof(Customer));
        if(!file)
            break;
        else
            if(e.custid == custid)
                continue;
        temp.write((char*)&e,sizeof(Customer));

    }
    file.close();
    temp.close();
    remove("Customer.dat");
    rename("temp.dat","Customer.dat");
}

long int Customer::getpos()
{
    ifstream file("Customer.dat",ios::in);
    Customer e;
    long int pos = -1;
    while(true)
    {
        file.read((char*)&e,sizeof(Customer));
        if(!file)
            break;
        else if(e.custid == custid)
            pos = (long int)file.tellg() - sizeof(Customer);
    }
    file.close();
    return pos;
}

void Customer::Modify()
{
    Customer e;
    do {
    e = Customer::findinfile();
    if(e.custid == -2)
        return;
    else if(e.custid == -1)
    {
        cout << "\n Sorry No record found.\n";
    }
    else
    {
        long int pos = e.getpos();
        e.modify_object();
        ofstream file("Customer.dat",ios::out|ios::ate);
        file.seekp(pos,ios::beg);
        file.write((char*)&e,sizeof(Customer));
        file.close();
    }
    cout << endl;
    system("pause");
    }while(true);
}

void Customer::modify_object()
{
    int exit = 0;
    int ch;
    do
    {
        system("cls");
        displaydata();
        cout << endl;
        cout << "Modify\n";
        cout << "1.Customer id\n";
        cout << "2.Name\n";
        cout << "3.Phone number\n";
        cout << "4.Exit\n";
        cout << "Enter your choice:";
        cin >> ch;
        switch(ch)
        {
        case 1:
        do
        {
            cout << "Enter new customer id : ";
            cin >> custid;
            fflush(stdin);
            if(custid<=0)
            {
                cout << "\nInvalid customer id\n";
            }
            else if(check_id(custid))
            {
                cout << "\nAlready an customer exists with same id.\n";
            }
            else
            break;
        }while(true);
        break;

        case 2:
        cout << "Enter new name: ";
        fflush(stdin);
        gets(name);
        break;

        case 3:
        do
            {
            cout<<"Enter new contact number: ";
            fflush(stdin);
            gets(phno);
            if (strlen(phno) == 10)
            break;
            else
            continue;
        }while(true);
        break;

        case 4: exit = 1;
                    }
    }while(exit == 0);

}

void Customer::Delete()
{
    Customer c = Customer::findinfile();
    c.deletefromdb();
}
char* Customer::classname()
{
    return "Customer";
}

