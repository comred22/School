//This program uses string stream which is used in the following ways
// (1) read numbers that are contained in strings
// (2) convert between numbers and strings

#include <iostream>
#include <iomanip> //for setw and setfill
#include <sstream> //for string stream
#include "List.h"
using namespace std;

//This function is not used in this program.
//It is FYI
int stringToInt(string s)
{
	//istringstream class reads characters from a string
	istringstream inStr(s);
	int n;
	inStr >> n;
	return n;
}

string intToString(int n)
{
	//ostringstream class writes characters to a sting
	//By writing to a string stream, you can convert numbers to strings

	ostringstream outStr; // You can also do to_string to convert to string

	//Use << operator to add a number to the stream
	//The number is converted into a sequence of characters
	//You can use all io manipulators for cout with ostringstream object
	outStr << setw(2) << setfill('0') << n;

	//To obtain the string for n, call str member function
	string output = outStr.str();
	return output;
}
int main() 
{

	cout << "\n*** List Test ***" << endl;

	List<string> list;// need to give specfic type// muliple classed but we send those data type to it
	string  initStr = "myString";
	const int SIZE = 6;

	if (list.isEmpty())
		cout << "list is empty" << endl;

	cout << "fill the list" << endl;
	for (int i = 0; i < SIZE; i++) {
		string new_str = initStr + intToString(i); // Since its a constant 
		list.insert(i, new_str);

	}
	// Fixed value but we do not know where it is stored 

	list.print();

	cout << "remove from position 3 and then 0" << endl;
	list.remove(3);
	list.remove(0);
	list.print();

	cout << "insert at position 2" << endl;
	initStr = "newlyInsertedString: ";
	string month = "Nov.";
	int day = 3;
	int year = 2021;

	ostringstream outStr;
	//build up more complex string out of string and int variables
	outStr << initStr << month << " " << day << "," << year;
	list.insert(2, outStr.str());
	list.print();

	try
	{
		int current_size = list.size();
		for (int i = 0; i < current_size; i++)
		{
			list.remove(0);
		}

	}
	catch (List<string>::OutOfRangeException& e)
	{
		cout << "Out of Range Expcetion occurred. \n"; // e.what returns a null charecter 
		

	}

	return 0;

}