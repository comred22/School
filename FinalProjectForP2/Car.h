#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;
class Car
{
private:
    int arrivalTimes;
    int timeStayed;
    enum CarType {COMPACT , TRUCK };
    CarType X;
    string licensePlate;
    int departureTime;
public:
    Car();

    Car(const string&);
    bool operator>(const Car& right); 
    bool operator< (const Car& right);
    friend ostream& operator<<(ostream&, const Car&);

    int timeCalculations(); // needs to be an int

    string parse(int, const string&);// removed not needed

    void testPrint();

    CarType StringToEnum(string);

    // We need a way to take input from the file:: DONE
    // We need  a parse 
    // 
    // We need getters and setters 

    int getarrivalTimes();
    void setArrivalTimes(int);

    int getTimeStayed();
    void setTimeStayed(int);

    CarType getCarTypes();
    void setCarTypes(CarType);

    string getlicensePlate();
    void setLicensePlate(string);

    int getDepatureTime();
    void setDepatureTime(int);


};

#endif