#include "orders.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include "customer.h"

using namespace std;

Order::Order()
{
    orderno = 0;
    strcpy(placed_date," ");
    initial_amt=0;
    wastage = 0;                                //>0
}



void Order::get_Data()
{
    cout<<"==========================================================";
    cout << "\n\t\t\t\t Order details:\n";
    do
    {
	cout << "Enter order no.                  : ";
    cin >> orderno;
    fflush(stdin);
    if(orderno<=0)
    {
        cout << "\nInvalid orderno\n";
    }
    else if(check_id(orderno))
    {
        cout << "\nAlready an order exists with same no.\n";
    }
    else
    break;
    }while(true);

    do
    {
	cout << "Enter customer id                : ";
    cin >> c.custid;
    fflush(stdin);
    if(c.custid<=0)
    {
        cout << "\nInvalid orderno\n";
    }
    else if(!Customer::check_id(c.custid))
    {
        cout << "No customer with the id found.\n";
    }
    else
    {
        ifstream file("Customer.dat",ios::in);
        Customer e;
        while(true)
        {
            file.read((char*)&e,sizeof(Customer));
            if(!file)
                break;
            else if(e.custid == c.custid)
            {
                c = e;
                break;
            }
        }
        break;
    }
    }while(true);

    cout<<"Enter placed date                : ";
    gets(placed_date);
    do
    {
    cout<<"Enter initial amount             : ";
    cin>>initial_amt;fflush(stdin);
    if(initial_amt>=0)
    break;
    else
    continue;
   }while(true);


    do
    {
	cout<<"Enter wastage                    : ";
    cin>>wastage;fflush(stdin);
    if(wastage>=0)
    break;
    else
     continue;
    }while(true);


    cout<<"\n=========================================================" << endl;

}

void Order::displaydata()

{
     cout<<"\n\t\t=====================================================";
    cout<<"\n\t\t\t\t     ORDER DETAILS ";
    cout<<"\n\t\t\t ORDER NO           :"<<orderno;
    cout<<"\n\t\t\t CUSTOMER ID        :"<<c.custid;
    cout<<"\n\t\t\t CUSTOMER NAME      :"<<c.name;
    cout<<"\n\t\t\t PLACED DATE        :"<<placed_date;
    cout<<"\n\t\t\t INITIAL AMOUNT     :"<<initial_amt;
    cout<<"\n\t\t\t WASTAGE            :"<<wastage;
    cout<<"\n\t\t=====================================================";
}

void Order::write()
{
    ofstream file("Order.dat",ios::out|ios::app);
    file.write((char*)this,sizeof(Order));
    file.close();
}

void Order::displayfromfile()
{
    ifstream file("Order.dat",ios::in);
    if(!file)
    {
        cout << "The file doesn't exist.";
        return;
    }
    Order e;
    cout <<endl <<  std::setfill( '-' ) << std::setw( 100 ) << '-'
               << std::setfill(' ') << std::endl;
    cout  << "| " << setw(10) << left <<"ORDER NO" << "| " << setw(10) << left <<"CUST ID" << "| "
    << setw(30) << left << "CUSTOMER NAME" << "| " << setw(20) << left << "PLACED DATE" << "| " << setw(20) << left << "INITIAL AMOUNT" << "|";
    cout << endl << std::setfill( '-' ) << std::setw( 100 )
              << '-';
    while(true)
    {
        file.read((char*)&e,sizeof(Order));
        if(!file)
            break;
        else{
            cout  << endl << std::setfill(' ')
            << "| " << setw(10) << left <<e.orderno << "| " << setw(10) << left <<e.c.custid << "| "
            << setw(30) << left << e.c.name << "| " << setw(20) << left << e.placed_date << "| "
            << setw(20) << left << e.initial_amt << "|";
        }
    }
    cout <<endl <<  std::setfill( '-' ) << std::setw( 100 ) << '-'<< std::setfill(' ')
               << std::endl;
    file.close();
}
int Order::displayfromfile( char* name)
{
    ifstream file("Order.dat",ios::in);
    Order e;
    int count = 0;
    cout <<endl <<  std::setfill( '-' ) << std::setw( 100 ) << '-'
               << std::setfill(' ') << std::endl;
    cout  << "| " << setw(10) << left <<"ORDER NO" << "| " << setw(10) << left <<"CUST ID" << "| "
    << setw(30) << left << "CUSTOMER NAME" << "| " << setw(20) << left << "PLACED DATE" << "| " << setw(20) << left << "INITIAL AMOUNT" << "|";
    cout << endl << std::setfill( '-' ) << std::setw( 100 )
              << '-';
    while(true)
    {
        file.read((char*)&e,sizeof(Order));
        if(!file)
            break;
        else
            if(strstr(strupr(e.c.name),strupr(name)))
            {cout  << endl << std::setfill(' ')
            << "| " << setw(10) << left <<e.orderno << "| " << setw(10) << left <<e.c.custid << "| "
            << setw(30) << left << e.c.name << "| " << setw(20) << left << e.placed_date << "| "
            << setw(20) << left << e.initial_amt << "|";
            count++;}
    }
    cout <<endl <<  std::setfill( '-' ) << std::setw( 100 ) << '-'<< std::setfill(' ')
               << std::endl;
    file.close();
    return count;
}

void Order::deletefile()
{
    remove("Order.dat");
}

Order Order::findinfile()
{
    int id;
    int ch;
    char name[30];
    do
    {
        system("cls");
        Order::displayfromfile();
        cout << "\n\n";
        cout << "1.Enter id\n";
        cout << "2.Find by customer name\n";
        cout << "3.Exit\n";
        cout << "Enter your choice:";
        cin >> ch;
        Order e;
        e.orderno = -2;
        switch(ch)
        {
            case 2:
                    cout << "Enter the customer name:";
                    fflush(stdin);
                    gets(name);
                    if(Order::displayfromfile(name)<1)
                    {
                        cout << "\n No record found.";
                        system("pause");
                        continue;
                    }
            case 1: cout << "Enter order id:";
                    cin >> id;
            break;
            case 3: return e;
            default: continue;
        }
        ifstream file("Order.dat",ios::in);
        while(true)
        {
            file.read((char*)&e,sizeof(Order));
            if(!file)
                break;
            else
                if(e.orderno == id)
                return e;

        }
        file.close();
        e.orderno = -1;
        return e;
    }while(true);


}

void Order::findanddisplayfromfile()
{
    Order e;
    do {
    e = Order::findinfile();
    if(e.orderno == -2)
        return;
    else if(e.orderno == -1)
    {
        cout << "\n Sorry No record found.\n";
    }
    else
        e.displaydata();
    cout << endl;
    system("pause");
    }while(true);
}
bool Order::check_id(int id)
{
    Order e;
    ifstream file("Order.dat",ios::in);
    while(true)
    {
        file.read((char*)&e,sizeof(Order));
        if(!file)
            break;
        else
            if(e.orderno == id)
            return true;

    }
    file.close();
    return false;
}

void Order::deletefromdb()
{
    ifstream file("Order.dat",ios::in);
    ofstream temp("temp.dat",ios::out);
    Order e;
    while(true)
    {
        file.read((char*)&e,sizeof(Order));
        if(!file)
            break;
        else
            if(e.orderno == orderno)
                continue;
        temp.write((char*)&e,sizeof(Order));

    }
    file.close();
    temp.close();
    remove("Order.dat");
    rename("temp.dat","Order.dat");
}

long int Order::getpos()
{
    ifstream file("Order.dat",ios::in);
    Order e;
    long int pos = -1;
    while(true)
    {
        file.read((char*)&e,sizeof(Order));
        if(!file)
            break;
        else if(e.orderno == orderno)
            pos = (long int)file.tellg() - sizeof(Order);
    }
    file.close();
    return pos;
}

void Order::Modify()
{
    Order e;
    do {
    e = Order::findinfile();
    if(e.orderno == -2)
        return;
    else if(e.orderno == -1)
    {
        cout << "\n Sorry No record found.\n";
    }
    else
    {
        long int pos = e.getpos();
        e.modify_object();
        ofstream file("Order.dat",ios::out|ios::ate);
        file.seekp(pos,ios::beg);
        file.write((char*)&e,sizeof(Order));
        file.close();
    }
    cout << endl;
    system("pause");
    }while(true);
}

void Order::modify_object()
{
    int exit = 0;
    int ch;
    do
    {
        system("cls");
        displaydata();
        cout << endl;
        cout << "Modify\n";
        cout << "1.Order no\n";
        cout << "2.Customer\n";
        cout << "3.Initial amount\n";
        cout << "4.Placed date\n";
        cout << "5.Wastage\n";
        cout << "6.Exit\n";
        cout << "Enter your choice:";
        cin >> ch;
        switch(ch)
        {
                case 1:
                {

                do
                {
                    cout << "Enter new order no.: ";
                    cin >> orderno;
                    fflush(stdin);
                    if(orderno<=0)
                    {
                        cout << "\nInvalid orderno\n";
                    }
                    else if(orderno == '.')
                    {
                        break;
                    }
                    else if(check_id(orderno))
                    {
                        cout << "\nAlready an order exists with same no.\n";
                    }
                    else
                        break;
                }while(true);
                }
                break;
                case 2:
                {
                    do
                    {
                        cout << "Enter customer id                  : ";
                        cin >> c.custid;
                        fflush(stdin);
                        if(c.custid<=0)
                        {
                            cout << "\nInvalid orderno\n";
                        }
                        else if(!Customer::check_id(c.custid))
                        {
                            cout << "No customer with the id found.";
                        }
                        else
                        {
                            ifstream file("Customer.dat",ios::in);
                            Customer e;
                            while(true)
                            {
                                file.read((char*)&e,sizeof(Customer));
                                if(!file)
                                    break;
                                else if(e.custid == c.custid)
                                {
                                    c = e;
                                    break;
                                }
                            }
                            break;
                        }
                    }while(true);
                }
                break;

                case 3:
                {
                    cout<<"Enter placed date               : ";
                    gets(placed_date);
                }
                break;
                case 4:
                {
                    do
                    {
                        cout<<"Enter initial amount                   : ";
                        cin>>initial_amt;fflush(stdin);
                        if(initial_amt>=0)
                        break;
                        else
                        continue;
                   }while(true);
               }
               break;

                case 5:
                {
                    do
                    {
                        cout<<"Enter wastage                       : ";
                        cin>>wastage;fflush(stdin);
                        if(wastage>=0)
                        break;
                        else
                         continue;
                    }while(true);
                }
                break;

                case 6: exit = 1;
        }

        }while(exit == 0);


}
void Order::Delete()
{
    Order e = Order::findinfile();
    e.deletefromdb();
}
char* Order::classname()
{
    return "Order";
}


Order_completed::Order_completed()
{
    status = ' ';
    final_amt = 0;
}
Order_completed::Order_completed(Order& o): Order(o)
{
    status = ' ';
    final_amt = 0;
}

void Order_completed::menu()
{
    int exit =0;
    int ch;
    do
    {
        system("cls");
        Order::displayfromfile();
        cout << endl;
        cout << "1.Cancel order\n";
        cout << "2.Complete order\n";
        cout << "3.View past orders\n";
        cout << "4.Exit\n";
        cout << "Enter your choice:";
        cin >> ch;
        system("cls");
        switch(ch)
        {
            case 1:
                {
                 Order o = Order::findinfile();
                 Order_completed o1(o);
                 o1.status = 'f';
                 o1.write();
                 cout << "\n Order " << o1.orderno << " is cancelled.";
                 o.deletefromdb();
                 system("pause");
                }
            break;
            case 2:
                {
                 Order o = Order::findinfile();
                 Order_completed o1(o);
                 o1.status = 's';
                 cout << "\nEnter the final amount:";
                 cin >> o1.final_amt;
                 o1.write();
                 cout << "\n Order " << o1.orderno << " is Completed.";
                 o.deletefromdb();
                 system("pause");
                }
            break;
            case 3:
                Order_completed::displayfromfile();
                Order_completed::viewreport();
                cout << endl;
                system("pause");
            break;
            case 4: exit = 1;
            break;

        }

    }while(exit == 0);

}
void Order_completed::displayfromfile()
{
    ifstream file("order-completed.dat",ios::in);
    if(!file)
    {
        cout << "The file doesn't exist.";
        return;
    }
    Order_completed e;
    cout <<endl <<  std::setfill( '-' ) << std::setw( 142 ) << '-'
               << std::setfill(' ') << std::endl;
    cout  << "| " << setw(10) << left <<"ORDER NO" << "| " << setw(10) << left <<"CUST ID" << "| "
    << setw(30) << left << "CUSTOMER NAME" << "| " << setw(20) << left << "PLACED DATE" << "| " << setw(20) << left << "INITIAL AMOUNT" << "|"
    << setw(20) << left << "FINAL AMOUNT" << "|"<< setw(20) << left << "STATUS" << "|";
    cout << endl << std::setfill( '-' ) << std::setw( 142 )
              << '-';
    while(true)
    {
        file.read((char*)&e,sizeof(Order_completed));
        if(!file)
            break;
        else{
            cout  << endl << std::setfill(' ')
            << "| " << setw(10) << left <<e.orderno << "| " << setw(10) << left <<e.c.custid << "| "
            << setw(30) << left << e.c.name << "| " << setw(20) << left << e.placed_date << "| "
            << setw(20) << left << e.initial_amt << "|"<< setw(20) << left << e.final_amt << "|";
             (e.status == 's')?cout << setw(20) << left << "COMPLETED": cout<< setw(20) << left <<"CANCELLED" ;
             cout << "|";
        }
    }
    cout <<endl <<  std::setfill( '-' ) << std::setw( 142 ) << '-'<< std::setfill(' ')
               << std::endl;
    file.close();
}
void Order_completed::viewreport()
{
    int total = 0;
    int cancelled = 0;
    int completed = 0;
    int fully_completed = 0;
    double total_income = 0;
    double compl_percent;
    ifstream file("order-completed.dat",ios::in);
    Order_completed o;
    while(true)
    {
        file.read((char*)&o,sizeof(Order_completed));
        if(!file)
            break;
        total++;
        total_income+=o.final_amt;
        if(o.status == 'f')
            cancelled++;
        else if(o.final_amt >= o.initial_amt)
            fully_completed++;
    }
    completed = total - cancelled;
    compl_percent = (double)fully_completed/completed*100;
    cout << "\nTotal orders:" << total;
    cout << "\nCancelled orders:" << cancelled;
    cout << "\nCompleted Orders:" << completed;
    cout << "\nFully Completed orders:" << fully_completed;
    cout << "\nFully completion percent:" << compl_percent << "%";
    cout << "\n\nTotal amount:" << total_income;
}
void Order_completed::write()
{
    ofstream file("order-completed.dat",ios::out|ios::app);
    file.write((char*)this,sizeof(Order_completed));
    file.close();
}

