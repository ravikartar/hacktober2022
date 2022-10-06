#include <iostream>
using namespace std;


class Employee
{
    public:
        char name[20];
        int id;

        void get()
        {
            cout<<"\nEnter name: ";
            cin>>name;
            cout<<"\nEnter employee id: ";
            cin>>id;
        }
    
};


class Regular: public Employee
{
    public:
        double DA;
        double HRA;
        double basic_salary;

       Regular(double d, double h, double b)
       {
          DA=d;
          HRA=h;
          basic_salary=b;
       }

     void display()
     {
            cout<<"\nSalary of the Regular employee is "<<(DA+HRA+basic_salary);
     }
    
};


class PartTime: public Employee
{
    public:
        int number_of_hours;
        double pay_per_hour;

        PartTime(int n, double p)
        {
            number_of_hours=n;
            pay_per_hour=p;
        }
        void display()
        {
            cout<<"\nSalary of the part-time employee is "<<(number_of_hours*pay_per_hour);
        }
};


int main()
{
    Employee e;
    e.get();
    float salary, da, hra, hour, pay;
    cout<<"Enter your basic salary, DA and HRA: ";
    cin>>salary>>da>>hra;
    
    Employee e1;
    e1.get();
    cout<<"Enter your total number of hours and pay per hour: ";
    cin>>hour>>pay;
    Regular r(da, hra, salary);
    r.display();

    PartTime p(hour, pay);
    p.display();

    return 0;
}
