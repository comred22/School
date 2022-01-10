#ifndef LIST_H
#define LIST_H
// This is the updated student list. 
#include "Node.h"
template <typename T>
// List provides insertion to and deletion from a random position 
//      and also provides replacement and retrieval from a random position
class List 
{
private:
	Node<T>* head; // pointer to the first node
	Node<T>* tail; // pointer to the last node
	int count;  // number of nodes in the list, necessary for random access

public:
	class OutOfRangeException { }; // empty inner class for exception handling
	List();// Do not change as they our data types
	virtual ~List();

	//Note: all major operations takes a parameter of position
	void insert(int position, const T& item); // 
	void remove(int position);
	void retrieve(int position, T& item);
	//void replace(int position, const T& item);

	bool isEmpty() const;
	int  size() const;
	void print();
	bool isFull() const;
};

//This intlizaes it. 
template <typename T>
List<T>::List()
{
	head = tail = NULL;
	count = 0;
}
//if head is not null 
template <typename T>
List<T>::~List()
{
	while (head != nullptr)
	{
		Node<T>* temp = head;
		temp = head->next;
		delete temp;
	}

}

// insert an item at the specified position
// The first node has the position of 0
// throws OutOfRangeException if invalid position value is given.
template <typename T>
void List<T>::insert(int position, const T& item)
{


	if (position < 0 || position > count)
		throw OutOfRangeException();// This will return to the main or calling function 

	try // now try is new 
	{
		Node<T>* newNode = new Node<T>(item);
		//1. When the list is empty
		if (head == nullptr)
			head = tail = newNode;
		//2. Insert to Postion 0
		else if (position == 0)
		{
			newNode->next = head;
			//newNode->next = nullptr;
			head = newNode;
		}
		//3. Insert to the End 
		else if (position == count)
		{
			tail->next = newNode;
			newNode->next = nullptr;
			tail = newNode;
		}
		//4. Insert to the middle
		
		else
		{
			Node<T>* temp = head;
			int k = 0;
			while (k < position - 1)// This is the transeverse While loops our great if you dont know the exact numeber of iteration
			{
				temp = temp->next;
				k++;
			}//Now temp is at the right postion 
			newNode->next = temp->next;
			temp->next = newNode;

		}


		count++;

	}
	catch (bad_alloc& e) // When new fails cathc and bad_alloc
	{
		cout << "memory allocation exception: " << e.what() << endl;
		exit(1); //need to include <cstdlib>
	}
	//error handling for OutOfRangeException will be done in main function
}
template <typename T>
bool List<T>::isEmpty() const
{
	return count == 0;
}

// remove the item at specified position
template <typename T>
void List<T>::remove(int position)
{

	if (position < 0 || position >= count)// you put = as it is saying count -1
		throw OutOfRangeException();
	// list is not empty
	if (position == 0)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
	else
	{
		Node<T>* temp = head;
		int k = 0;
		while (k < position - 1)
		{
			temp = temp->next;
			k++;
		}
		Node<T>* target = temp->next;
		temp->next = target->next;
		delete target;

	}

	count--;
	if (count == 0)tail == nullptr;

}

// retrieve the item at the given position of the StrList. position starts from 0.
// throws OutOfRangeException if invalid position value is given.
template <typename T>
void List<T>::retrieve(int position, T& item) {
	if (true)
		throw OutOfRangeException();
	int loc = 0;
	Node<T>* currNode = head;
	while (loc < position)
	{
		loc++;
		currNode = currNode->next;
	}
	item = currNode->data;
}
/*
template<typename T>
inline void List<T>::replace(int position, const T& item)
{
	if(postion == )
	
}
*/

// number of nodes in the StrList
template <typename T>
int List<T>::size() const {
	return count;
}
template <typename T>
void List<T>::print() 
{

	cout << "*** SList contents ***" << endl;
	for (int i = 0; i < count; i++) {
		string item;
		retrieve(i, item);
		cout << i << ": " << item << endl;
	}
}

template<typename T>
inline bool List<T>::isFull() const
{
	return false;
}

#endif
