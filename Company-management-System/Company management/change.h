#ifndef CHANGEINEMPLOYEE_H
#define CHANGEINEMPLOYEE_H
#include <iostream>
#include <cstdlib>
using namespace std;
template <class T>
void change()
{
    int ch;
    int exit =0;
    T e;
    do
    {

        system("cls");
        cout << "\n\n\n\n\t\t\t\tChange " << T::classname() << " \n\n";
        cout << "\t\t\t\t1.Add\n";
        cout << "\t\t\t\t2.Delete\n";
        cout << "\t\t\t\t3.Delete file\n";
        cout << "\t\t\t\t4.Modify\n";
        cout << "\t\t\t\t5.Exit\n";
        cout << "\n\n\t\t\t\tEnter your choice:";
        cin >> ch;
        system("cls");
        switch(ch)
        {
            case 1:e.get_Data();
                   e.write();
                   system("pause");
            break;
            case 2:T::Delete();
            system("pause");
            break;
            case 3: T::deletefile();
            system("pause");
            break;
            case 4: T::Modify();
            system("pause");
            break;
            case 5: exit = 1;
            break;
        }
        cout << endl;

    }while(exit == 0);

}


#endif // CHANGEINEMPLOYEE_H
