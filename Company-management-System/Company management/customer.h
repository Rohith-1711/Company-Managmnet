#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
    int custid;
    char name[30];
    char phno[11];


public:
    Customer();
    void get_Data();
    void displaydata();
    void write();
    static void displayfromfile();
    static int displayfromfile(char*);
    static void deletefile();
    static Customer findinfile();
    static void findanddisplayfromfile();
    static bool check_id(int id);
    void deletefromdb();
    static void Modify();
    void modify_object();
    long int getpos();
    static void Delete();
    static char* classname();
    friend class Order;
    friend class Order_completed;

};

#endif
