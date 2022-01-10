/* This program show how to use a function pointer

1. Functions are stored in memory. You can ask for the address of a function
2. You can store the address of a function to a variable called function pointer.
3. Function pointer variable declaration. 
	syntax: return_type (*function_pointer_variable_name)(parameter list);

4. Function pointers can be assigned, pass to and from functions, 
	placed in arrays etc. 

5. Callback is a piece of executable code passed to functions and usually used in event driven programming. "Call this function back when a certain event happens"
   In C and C++, callbacks are implemented by passing function pointers
*/

#include <iostream>
#include <cstdlib>

using namespace std;

void print(int a[], const int SIZE)
{
    cout << "== print the array ==" << endl;
	for(int i = 0; i < SIZE; i++)
		cout << a[i] << " ";
	cout << endl;
}

void increment(int a[], const int SIZE)
{
	for(int i = 0; i < SIZE ; i++)
		a[i] += 1;
}
void decrement(int a[], const int SIZE)
{
	for(int i = 0; i < SIZE ; i++)
		a[i] -= 1;
}

int findLargest(int a[], const int SIZE)
{
    cout << "== findLargest ==" << endl;
	int largest = a[0];
	for(int i = 1; i < SIZE ; i++) {
		if(a[i] > largest)
			largest = a[i];
	}
	return largest;
}

void displayMenu()
{
	cout << "-----------------" << endl;
	cout << "0. Increment" << endl;
	cout << "1. Decrement" << endl;
    cout << "2. Exit"      << endl;
	cout << "-----------------" << endl;
	cout << "Enter a number to select command : ";
}

void callBack(void (*fp)(int [], const int), int a[], int SIZE)
{
	fp(a, SIZE);
}


int main()
{
	const int SIZE = 5;
	int a[SIZE] = {0, 1, 2, 3, 4};

	//function pointer usage demo. 
	void (*fp1)(int[], const int) = NULL;

	//set the function pointer variable to the address of a function
	//fp1 can assigned to different functions as long as those functions return the same type 
	//and have the same types of parameters and the number of parameters
	fp1 = &print;

	//call print function using function pointer
	fp1(a, SIZE); //same as print(a, SIZE);

	fp1 = &increment;
	fp1(a, SIZE); //same as increment(a, SIZE);

	fp1 = &print;
	(*fp1)(a, SIZE);

	//A function name itself can be used as the address of a function
	int (*fp2)(int[], const int) = findLargest;  
	cout << "Largest: " << fp2(a, SIZE) << endl;

	
    void (*fp3[2])(int[], const int); 
    fp3[0] = increment;
    fp3[1] = decrement;

	//callback function demo
    while(true) {
	    displayMenu();
	    int command;
	    cin >> command;
	    if(!cin)  { //You can change this part to continue
	    	cout << "Invalid Input" << endl;
	    	exit(1);
	    }
        if(command >= 2) 
            break;
        else
	   	    callBack(fp3[command], a, SIZE);
        
	    (*fp1)(a, SIZE);
    }
	return 0;
}
	
