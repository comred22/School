#include <iostream>
#include <iomanip>
#include "Heap.h"  

using namespace std;

void print(int* p, const int );

int main(){
    Heap h;
    int number[] = {5, 10,4,3,1,15,11,12,20,19,2};
    cout << "Original array : \n";
    print(number, 11);

    cout << "After building a minHeap : \n";
    for (int i = 0; i < 11; i++)
    {
        h.insert(number[i]);
    }
    h.display();

    cout << "Sorting number in ascending order : \n";
    try
    {
        for (int i = 0; i < 11; i++)
        {
        cout << setw(3) << h.removeMin();
        }
        
    }catch (Heap::HeapEmptyException& empty){
        cout << "The heap is empty : \n";
    }

    h.display();
    return 0;
}

void print(int* p, const int SIZE){
    for(int i = 0;i < SIZE ; i++){
        cout <<setw(3) <<p[i];
        cout << endl;
    }

}