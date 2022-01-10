#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()
{
    cout << "\t Node()" <<  this << endl;
}
Node::Node(int d , Node* n) 
{
    Node* head = NULL;
    Node* prev = NULL;
    Node* temp = new Node;

    cout << "\t Node(int)" << this << endl;
    for(int i = 0; i < 10; i++) 
    {
        int item = rand() % 10;
        Node* temp = new Node;

        if(i == 0) 
        { 
            head = temp;
            prev = head;
        }

        else 
        {
            prev->next = temp;
            prev = temp;
        }

        temp->data = item;
        temp->next = NULL;
        this -> data = d; 
        this -> next = n;
        
    if(i == 0) 
    { 
        head = temp;
        prev = head;
        }
        else 
        {
            prev->next = temp;
            prev = temp;
        }
    }
}
Node::~Node()
{
    cout << "\t `Node" << endl;
}
// g++ -c followed by th CPP file name in windos terminal 
// MakeFile 