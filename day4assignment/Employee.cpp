#include<iostream>
using namespace std;
class Employee
{
    private:
        int eid;
        const char* ename;
        double basicSalary;
        
    public:
        void setData(int i, const char* n, double s)
        {
            eid = i;
            ename = n;
            basicSalary = s;
        }
        void displayData()
        {
            cout<<"ID: "<<eid<<endl;
            cout<<"Name: "<<ename<<endl;
            cout<<"Basic Salary: "<<basicSalary<<endl;

        }
        double calculateSalary()
{
    return basicSalary;
}
        //calculate salary overload function
        double calculateSalary(double bonus)
        {
            return basicSalary + bonus;
        }

        double calculateSalary(double bonus, double overtime)
        {
            return basicSalary + bonus + overtime;
        }
        double calculateSalary(double hourly_rate,int hours_worked)
        {
            return basicSalary + (hourly_rate * hours_worked) ;
        }
        friend ostream& operator<<(ostream& out, const Employee& e);

    };
        ostream& operator<<(ostream& out, const Employee& e)
        {
            out<<"ID: "<<e.eid<<endl;
            out<<"Name: "<<e.ename<<endl;
            out<<"Basic Salary: "<<e.basicSalary<<endl;
            return out;
        }


int main()
{
    Employee e1;
    e1.setData(1, "Omkar", 50000.0);
    e1.displayData();
    Employee e2;
    e2.setData(2, "Rugved", 60000.0);
    e2.displayData();
    cout<<e1;
    cout<<e2;
    cout<<"Salary of e1: "<<e1.calculateSalary(5000.0)<<endl;
    cout<<"Salary of e2: "<<e2.calculateSalary(5000.0, 1000.0)<<endl;//what is errror = 
    cout<<"Salary of e1: "<<e1.calculateSalary(100.0, 40)<<endl;

    return 0;
}
