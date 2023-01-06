#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Personal_details
{
    public:
    char name[30];
    int empid;
    char aadhar[20];
    char doj[20];
    float basic_sal;
    char contact_no[11];
    char dept[20];
    char desig[20];


};
class salary_details
{
public:
    float no_of_present;
    float overtime;
    float incentive;


};

class Employee
{
    Personal_details pdetails;
    salary_details sdetails;
public:
    Employee();
    void get_Data();
    void displaydata();
    void display_pdetails();
    void display_sdetails();
    void write();
    static void displayfromfile();
    static int displayfromfile(char*);
    static void deletefile();
    static Employee findinfile();
    static void findanddisplayfromfile();
    static bool check_id(int id);
    void deletefromdb();
    static void Modify();
    void modify_object();
    long int getpos();
    static void Delete();
    static char* classname();

};
#endif // EMPLOYEE_H
