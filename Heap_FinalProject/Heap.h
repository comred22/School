#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "Car.h"

using namespace std;

class Heap 
{
private:
    vector<Car*> elements;  //vector for dynamic resizing
    // Seemed like a waste of time To keep doing the math for the current index so I 
    // Simply made a way to call a function to get the index 
    // What Do I need parent Index 
    // Left and Right child index 
    int getleftMostChild_index(int index);
    int getRightMostChild_index(int index);
    int getParet_index(int index);

    // We needed a way to get the value that is at that index.
    Car* getLeftChildValue(int index);
    Car* getRightChildValue(int index);
    Car* getParentValue(int index);

public:
    Heap();
    //~Heap(); not needed since their is no pointers 
    void   insert(Car* e); // adds a new element to this heap
    Car* top() const;      // gets the min element in the heap without removal
    Car* removeMin();      // removes the min element from the heap
    int    size() const;     // returns the # of elements in the heap
    void display();
    void fix_Heap();
    

    class HeapEmptyException{};
};
#endif
