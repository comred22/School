#include <iostream>
#include "DB.h"

using namespace std;

int main()
{
    // Creat a DB in the heap
    DB *p = new DB;
    p->push(1);
    p->displaydata();

    p->pop();
    p->pop();
    cout << "----- After removing 2 -----" << endl;
    p->displaydata();// we call it a 2nd time after removing 2 numbers 
    

    delete p;
    return 0;
}

// We will later turn this into a .exe

//We will Go through make file in lab
    // p -> size();// can't access these because their not apart of the member function
    // struct everthing is public Class something our public and some our private
    // 5 pushes

    //p ->push(random);