#include <iostream>
#include <iomanip>
#include <sstream>
#include "S_Employee.h"
#include "Employee.h"
using namespace std;

S_Employee::S_Employee() : Employee()
{
    salary = 0;
    cout << "S_Employee() : " << this << endl; 
} 
S_Employee::S_Employee(const string& input) : Employee(input.substr(0, 71)) 
{
    cout << "S_Employee(const string&) : " << this << endl;

    istringstream ss(input.substr(72));
    string field;

    ss >> field;
    salary = stof(field);
} 
S_Employee::~S_Employee()
{
    cout << "~S_Employee() : " << this << endl;
}
double S_Employee::getSalary() const
{
    return salary;
}
void S_Employee::setSalary(double field)
{
    salary = field;
}
void S_Employee::display(ostream& out)
{
    Employee::display(out);
    out << right << setw(13) << salary << endl;
}