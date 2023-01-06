#include <iostream>
#include "Employee.h"
#include "mainscreen.h"
#include "customer.h"
#include "change.h"
#include "orders.h"
using namespace std;

void homescreen()
{
    int exit = 0;
    int ch;
    do
    {
        system("cls");
        cout << "\n\n\n\n\t\t\t\tHome Screen\n\n";
        cout << "\t\t\t\t1.User\n";
        cout << "\t\t\t\t2.Administrator\n";
        cout << "\t\t\t\t3.Exit\n";
        cout << "\n\n\t\t\t\tEnter your choice:";
        cin >> ch;
        switch(ch)
        {
            case 1: user();
            break;
            case 2: admin();
            break;
            case 3: exit = 1;
            break;
        }
    }while(exit == 0);
}

void intro()
{
    cout << "\n\n\t\t\t\t"
       << "----------------" <<endl<<endl;
   cout << "\t\t\t\t"
       << " VENTURE COMPANY" <<endl<<endl;
       cout << "\t\t\t\t"
       << "----------------" <<endl<<endl;
    cout << "\n\n\t\t\t\tEmail:venturescrews@gmail.com" << endl;
    cout << "\t\t\t\tPhno : 1234567890" << endl;
}

void user()
{
    int ch;
    do
    {
        system("cls");
        cout << "\n\n\n\t\t\t\tUser \n";
        cout << "\t\t\t\t----  \n";
        cout << "\t\t\t\t1.Display Employees\n";
        cout << "\t\t\t\t2.Display details of a particular employee\n";
        cout << "\t\t\t\t3.Display Customers\n";
        cout << "\t\t\t\t4.Display Orders\n";
        cout << "\t\t\t\t5.Exit\n";
        cout << "\n\n\t\t\t\tEnter your choice:";
        cin >> ch;
        system("cls");
        switch(ch)
        {
            case 1:Employee::displayfromfile();
            system("pause");
            break;
            case 2: Employee::findanddisplayfromfile();
            system("pause");
            break;
            case 3: Customer::displayfromfile();
            system("pause");
            break;
            case 4: Order_completed::menu();
            break;
            case 5: return;

        }
        cout << endl;

    }while(true);

}

void admin()
{
    int exit =0;
    int ch;
    do
    {
        system("cls");
        cout << "\n\n\n\t\t\t\tAdmin \n";
        cout << "\t\t\t\t.....  \n";
        cout << "\t\t\t\t1.Change in employee.dat\n";
        cout << "\t\t\t\t2.Change in customers.dat\n";
        cout << "\t\t\t\t3.Change in orders.dat\n";
        cout << "\t\t\t\t4.Exit\n";
        cout << "\n\n\t\t\t\tEnter your choice:";
        cin >> ch;
        system("cls");
        switch(ch)
        {
            case 1:
                 change<Employee>();
            break;
            case 2:
                change<Customer>();
            break;
            case 3:
                change<Order>();
            break;
            case 4: exit = 1;
            break;

        }
    }while(exit == 0);

}

