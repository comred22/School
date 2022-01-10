#include <iostream>
#include "H_Employee.h"
#include "S_Employee.h"
#include "Employee.h"
#include <string>
#include <fstream>
using namespace std;

int main()
{
    Employee* p[33];

    fstream fin_s;
    fin_s.open("salaried.txt", ios::in);

    if(fin_s.fail())
    {
        cout << "File failed to open" << endl;
        exit(1);
    }

    string input;
    int s_count = 0;

    while (getline(fin_s, input))
    {
        if(input != "")
        {
            p[s_count++] = new S_Employee(input);
        }
    }

    fin_s.close();

    fstream fin_h;
    fin_h.open("hourly.txt", ios::in);
    
    if(fin_h.fail())
    {
        cout << "File failed to open" << endl;
        exit(1);
    }

    int h_count = s_count;

    while (getline(fin_h, input))
    {
        if(input != "")
        {
            p[h_count++] = new H_Employee(input);
        }
    }

    fin_h.close();
    cout << endl;

    //Display S Employees
    for (int i = 0; i < s_count; i++)
    {
        p[i]->display(cout); 
    }

    //Display H Employees
    for (int i = s_count; i < h_count; i++)
    {
        p[i]->display(cout);
    }

    cout << "Number of Employees = " << Employee::getEmpSize() << endl << endl;

    //Deallocation 
    for (int i = 0; i < h_count; i++)
    {
        delete p[i];
    }    
    
    cout << "\nSize of Employee is   : " << sizeof(Employee) << endl;
    cout << "Size of S_Employee is : " << sizeof(S_Employee) << endl;
    cout << "Size of H_Employee is : " << sizeof(H_Employee) << endl;

    return 0;
}