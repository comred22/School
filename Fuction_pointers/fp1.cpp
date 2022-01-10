
#include <iostream>
using namespace std;

//increment() is overloaded
void increment(int x)
{
    x++;
}

void increment(int& x)
{
    x++;
}


int main()
{
    //declare function pointers
    void (*fp1)(int) = NULL;
    void (*fp2)(int&) = NULL;

    int value = 100;
    fp1 = increment;
    fp1(value);
    cout << "value after the function call w/o ref = " << value << endl; 
    (*fp1)(value);
    cout << "value after the function call w/o ref = " << value << endl; 

    fp2 = increment;
    fp2(value);
    cout << "value after the function call w ref = " << value << endl; 
    (*fp2)(value);
    cout << "value after the function call w ref = " << value << endl; 


    return 0;
}

