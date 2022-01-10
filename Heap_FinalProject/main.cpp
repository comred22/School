#include "Car.h"
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char** argv)// command line arugments 
{
    Car* parkingBay[20];

    fstream file;
    file.open("park.txt", ios::in);

    if(file.fail())
    {
        cout << "File failed to open" << endl;
        exit(1);
    }

    string input;
    int s_count = 0;

    while (getline(file, input))
    {
        if(input != "")
        {
            parkingBay[s_count++] = new Car(input);// need a Constructor that takes on permater. 
        }
    }

    file.close();
}