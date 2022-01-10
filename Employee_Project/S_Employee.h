#ifndef  S_EMPLOYEE_H
#define  S_EMPLOYEE_H

#include <string>
#include "Employee.h"

using namespace std;

class S_Employee : public Employee {
private:
    double salary;

public: 
    S_Employee(); //constructor
    S_Employee(const string&); //constructor
    ~S_Employee();
    double getSalary() const;
    void   setSalary(double);
    virtual void   display(ostream&);
    
};
#endif

