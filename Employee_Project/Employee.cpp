#include "Employee.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

int Employee::size = 0; //Must be outside of functions

Employee::Employee()
{
    cout << "Employee() : " << this << endl;

    setCode("");
    setSSN("");
    setFirst("");
    setLast("");
    setDept("");
    setRole("");

    size++;
}
Employee::Employee(const string& input)
{
    cout << "Employee(const string&) : " << this << endl;

    istringstream ss(input);

    string field;
    int count = 0;

    while (ss >> field)
    {
        parse(count, field);
        count++;
    }
    size++;
} 
Employee::~Employee()
{
    cout << "~Employee() : " << this << endl;
    size--;
}
void Employee::parse(int count, string field)
{
    switch (count)
        {
            case 0: setCode(field);
                break;
            case 1: setSSN(field);
                break;
            case 2: setFirst(field);
                break;
            case 3: setLast(field);
                break;
            case 4: setDept(field);
                break;
            case 5: setRole(field);
                break;
        }   
}
string Employee::getCode() const
{
    return code;
}
void Employee::setCode(string field)
{
    code = field;
}
string Employee::getSSN() const
{
    return ssn;
}
void Employee::setSSN(string field)
{
    ssn = field;
}
string Employee::getFirst()const
{
    return first;
}
void Employee::setFirst(string field)
{
    first = field;
}
string Employee::getLast() const
{
    return last;
}
void Employee::setLast(string field)
{
    last = field;
}
string Employee::getDept() const
{
    return department;
}
void Employee::setDept(string field)
{
    department = field;
}
string Employee::getRole() const
{
    return role;
}
void Employee::setRole(string field)
{
    role = field;
}
void Employee::display(ostream& out)
{
    out << left << setw(6) << code << setw(15) << ssn << setw(10)
    << last << setw(15) << first << setw(17) <<left << department << setw(24) << role;
}
int Employee::getEmpSize()
{
    return size;
}