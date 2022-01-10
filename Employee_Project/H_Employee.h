#ifndef H_EMPLOYEE_H
#define H_EMPLOYEE_H

#include <string>
#include "Employee.h"

using namespace std;

class H_Employee : public Employee {
private:
    int hoursWorked;
    double payRate;
public: 
    H_Employee(); 
    H_Employee(const string&); 
    ~H_Employee();
    int  getHoursWorked();
    void setHoursWorked(int);
    int  getPayRate();
    void setPayRate(double);
    virtual void display(ostream&);
    
    
};
#endif

