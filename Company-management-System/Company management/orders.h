#ifndef ORDER_H
#define ORDER_H
#include "customer.h"
class Order
{
protected:
    int orderno;
    Customer c;
    char placed_date[20];
    double initial_amt;
    int wastage;
public:
    Order();
    void get_Data();
    void displaydata();
    void write();
    static void displayfromfile();
    static int displayfromfile(char*);
    static void deletefile();
    static Order findinfile();
    static void findanddisplayfromfile();
    static bool check_id(int id);
    void deletefromdb();
    static void Modify();  //get id from user, modify and write
    void modify_object();  // just modify the object
    long int getpos();    //o.getpos()
    static void Delete();
    static char* classname();



};

class Order_completed: public Order
{
    char status;
    double final_amt;
public:
    Order_completed();
    Order_completed(Order&);

    static void menu();
    void write();
    static void displayfromfile();
    static void viewreport();
};
#endif // ORDER_H
