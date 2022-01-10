#include "Node.h"

class DB
{
    // member data and member variable, data 
    // store the data from Node and keeps it in a single link list 
private:
    Node* head;
    int size;


public:
    // Member functions
    DB();
    ~DB();
    void push(int);
    void pop();
    void displaydata();
};