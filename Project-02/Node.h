struct Node 
{
	// data attributes, data memebers, membervaribles 
	int data;
	Node* next;
	// Member functions 
	Node();// default constructor; When a varaible of the type is created
	Node(int, Node*); // constructor 
	~Node(); // destructor autmatically called when a varible is out of scope.
};
// function overloading is when you call multiple instance of of function with a diffrnet name
// OVERLAODING as long a function sginatures are diffrent you can have multiple
 // Goes to line 8 with data you send to the argument
//You can call Node1 with diffrent signature.
//int main() 
//{
	//Node node1; // goes to line 7 
	//Node node2(25, nullptr);
	//return 0;  // this is out of scope the stack will be wiped from the ram when this is called.

	// node 2 goes away First before node 1 because it has more values and is higher on the stack.
	//node . h is a way to make a call kinda 
//}
