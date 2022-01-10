
#include <iostream>
using namespace std;

void increment(int x)
{
    x++;
    cout << "inside increment, x = " << x << endl;
}

void decrement(int& x)// callback function. YOu can pass a peice of code to another fuction. 
{
    x--;
    cout << "decrement, x = " << x << endl;
}

void fun(int x, void(*fp)(int&)) // fun call backs to Decrement
{
    fp(x);
}


int main()
{
    //declare function pointers
    void (*fp1)(int) = NULL;
    void (*fp2)(int&) = NULL;
    int* pInt = new int;
    double* pDouble = new double;
    static int value;
    static int initValue = 0;
    

    cout << "local variable, fp1's (stack) address   = " << &fp1 << endl;
    cout << "local variable, fp2's (stack) address   = " << &fp2 << endl;
    cout << "pInt's heap address                     = " << pInt << endl;
    cout << "pDouble's heap address                  = " << pDouble << endl;
    cout << "uninitialized static variable's address = " << &value << endl;
    cout << "initialized static variable's address   = " << &initValue << endl;
    
    cout << "address of increment()                  = " <<  reinterpret_cast<void*> (increment) << endl;
    cout << "address of decrement()                  = " <<  reinterpret_cast<void*> (decrement) << endl;
    cout << "address of fun()                        = " <<  reinterpret_cast<void*> (fun) << endl;
    cout << "address of main()                       = " <<  reinterpret_cast<int*> (main) << endl;
    cout << "fp1 = " << fp1 << endl;
    cout << "fp2 = " << fp2 << endl;

    return 0;
}


