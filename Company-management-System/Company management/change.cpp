#include "change.h"
#include "Employee.h"
#include <iostream>

using namespace std;
template <class T>
void changeinemployee()
{
    int ch;
    int exit =0;
    T e;
    do
    {
        system("cls");
        cout << "\t\tChange in Employees \n\n";
        cout << "1.Add employee\n";
        cout << "2.Delete employee\n";
        cout << "3.Delete file\n";
        cout << "4.Modify employee\n";
        cout << "5.Exit\n";
        cout << "Enter your choice:";
        cin >> ch;
        system("cls");
        switch(ch)
        {
            case 1:e.get_Data();
                   e.write();
            break;
            case 2:T::Delete();
            break;
            case 3: T::deletefile();
            break;
            case 4: T::Modify();
            break;
            case 5: exit = 1;
            break;
        }
        cout << endl;
        system("pause");
    }while(exit == 0);

}
