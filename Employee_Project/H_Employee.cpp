#include <iostream>
#include <iomanip>
#include <sstream>
#include "H_Employee.h"
#include "Employee.h"
using namespace std;

H_Employee::H_Employee() : Employee()
{
    hoursWorked = 0;
    payRate = 0;
} 
H_Employee::H_Employee(const string& input) : Employee(input.substr(0,70))
 {
    cout << "H_Employee(const string&) : " << this << endl;

    istringstream ss(input.substr(71));
    string field;
    
    ss >> field;
    hoursWorked = stoi(field);

    ss >> field;
    payRate = stof(field);
 } 
 H_Employee::~H_Employee()
{
    cout << "~H_Employee() : " << this << endl;
}
int H_Employee::getHoursWorked()
{
    return hoursWorked;
}
void H_Employee::setHoursWorked(int field)
{
    hoursWorked = field;
}
int H_Employee::getPayRate()
{
    return payRate;
}
void H_Employee::setPayRate(double field)
{
    payRate = field;
}
void H_Employee::display(ostream& out)
{
    Employee::display(out);
    out << fixed << setprecision(2) << left << setw(8) << hoursWorked << right << setw(10) << payRate << endl;
}


