#include <iostream>
#include <iomanip>
#include "Heap.h"

Heap::Heap()
{
    elements.push_back(nullptr);// This represntes the first in the array The stop point
}
void Heap:: insert(Car* e)// E just represents Key 
{
    //1. we our simply adding a key
    elements.push_back(e);
    //2. push to the heap compare to the Heap
    int curIdx = elements.size() - 1;
    //3.Make a while loop, When current key is less than or when parent is less than or reach top root. 
    bool flag = true; // how we e
    do
    {
        int pIdx = curIdx / 2;

        if(curIdx == 1 || elements[pIdx] > e ){
            flag = false;
            break;
        }
        else{
            elements[curIdx] = elements[pIdx];
            curIdx = pIdx;
            // contue condtion. 
        }
    } while (flag);
    
    elements[curIdx] = e;
     
}
Car* Heap::top() const
{
    if(elements.size() - 1 <= 0){
        throw HeapEmptyException();
    }
    return elements[1];
}    

Car* Heap::removeMin()
{
    if(elements.size() - 1 <= 0){
        throw HeapEmptyException();
    }
    int last_index = elements.size() - 1;
    Car* last = elements[last_index];
    Car* last = elements[last_index];
    elements.pop_back();
    if (last_index > 1)
    {
        elements[1]= last;
        fix_Heap();
    }
    
    return last;
}   
int Heap::size() const
{
    return elements.size() - 1;
}   
void Heap::display()
{
    for(int i = 1;i <= size(); i++)
    {
        cout << setw(3)<< elements[i];
        cout << endl;
    }
}
void Heap::fix_Heap()
{
    Car* root = elements[1];
    int curIdx = elements.size() - 1;


    int index = 1;
    bool flag = true;
    while (flag)
    {
        int childIndex = getleftMostChild_index(index);
        if(childIndex <= curIdx) // We want the child index if it smaller on the left 
        {
            // we need to get the child of the node
            Car* child = getLeftChildValue(index);

            if (getRightMostChild_index(index)<= curIdx && getRightChildValue(index) > child)
            {
                childIndex = getRightMostChild_index(index);// This store what index it's at
                child = getRightChildValue(index); // This store the Value of the child
            }
            // Check to see if the child is larger than the root
            if(child > root)
            {
                // Promote the Child 
                elements[index] = child;
                index = childIndex;
            }
            else
            {
                //Root is larger than both children
                // our tree is in order 
                flag = false;
            }
        }
        else
        {
            // No children 
            flag = false;
        }

        
    }
    elements[index] = root;

}

int Heap::getleftMostChild_index(int index){
    return 2 * index;
}
int Heap::getRightMostChild_index(int index){
    return 2 * index + 1;
}
int Heap::getParet_index(int index){
    return index / 2;
} 

Car* Heap::getLeftChildValue(int index){
    return elements[2 * index];
}
Car* Heap::getRightChildValue(int index){
    return elements[2 * index + 1];
}
Car* Heap::getParentValue(int index){
    return elements[index / 2];// so if we have 2 as we index and we divide we have 1 
}