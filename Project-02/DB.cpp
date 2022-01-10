#include <iostream>
#include "DB.h"

using namespace std;
DB::DB()
{
    cout << "DB() : " << this << endl;
}
DB::~DB()
{
    cout << "DB::~DB : ()" << endl;
}
void DB::push(int j) // main will call the random number and push
{
    Node* head = new Node();
    size;
    int random;
    cout << "DB::Push : (" << j << ")" << endl;
    for (int i = 0; i <= 5; i++)
    {
        random = rand() % 10 - 100;
        Node(random);
    }
}
void DB::pop() // needs to remove 2 varibles from the lnked list array
{
    Node *n;
    bool checker = false;
    
    cout << "DB::Pop : ()" << endl;
    while (head->next != NULL)
    {
        Node* temp = head;
        cout << head->next->data << " ";
        temp = head->next;
        delete temp;

    }

}
void DB::displaydata()
{
    cout << "-----This display the 5 Random numbers in the list----- " << endl;
   while (this->head !=nullptr)
   {
       cout << " " <<this-> head-> data << " ";
       this->head - this-> head;
   }
   
};
// Data base  needs to send the values to the node for the node to store it. in a Link list