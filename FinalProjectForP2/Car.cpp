#include "Car.h"
#include "Heap.h"

Car::Car()
{
    setArrivalTimes(0);
    setTimeStayed(0);
    setCarTypes(COMPACT);
    setLicensePlate("");
    setDepatureTime(timeCalculations());
}


bool Car::operator>(const Car& right) // Used to compare 
{
    if (this->departureTime > right.departureTime)
    {
        return true;
    }
    else
    return false;
    
}
bool Car::operator< (const Car& right) // will be the heao 
{
    if (this->departureTime < right.departureTime)
    {
        return true;
    }
    else
    return false;

}
ostream& operator<<(ostream&, const Car& input)
{
    if (input.X == input.COMPACT)
    {
        cout << input.arrivalTimes << " " << input.timeStayed << " " << "COMPACT" << " " << input.licensePlate << endl;
    }else{
        cout << input.arrivalTimes << " " << input.timeStayed << " " << "TRUCK" << " " << input.licensePlate << endl;
    }
    
    
}
Car:: Car(const string& input){
    CarType c;
    istringstream ss(input.substr(0));
    string field;
    
    ss >> field;
    arrivalTimes = stoi(field);
    
    ss >> field;
    timeStayed = stof(field);

    ss >> field;
    c = StringToEnum(field);

    ss >> field;
    licensePlate = field;

    departureTime = timeCalculations();

    if(c == TRUCK)
    {
        Heap truckHeap;
        truckHeap.insert(this);
    }
    if(c == COMPACT )
    {
        Heap compactHeap;
        compactHeap.insert(this);
    }


}


    int Car::getarrivalTimes(){
        return arrivalTimes;
    }
    void  Car::setArrivalTimes(int y){
        arrivalTimes = y;
    }

    int  Car::getTimeStayed(){
        return timeStayed;
    }
    void  Car::setTimeStayed(int y){
        timeStayed = y;
    }

    Car::CarType  Car::getCarTypes(){
        return X;
    }
    void  Car::setCarTypes(CarType x){
        X = x;
    }

    string  Car::getlicensePlate(){
        return licensePlate;
    }
    void  Car::setLicensePlate(string x){
        licensePlate = x;
    }

    int Car:: getDepatureTime(){
        return departureTime;

    }
    void Car:: setDepatureTime(int y){
        departureTime = y;
    }

 int Car::timeCalculations()
 {
    int hour, min, newTime;
    hour = getarrivalTimes() / 60;
    min =  hour/60;
    for (int i = 0; i < getTimeStayed(); i++)
    {
        min++;
        if (min >= 60)
        {
            hour  + 1;
            min = 0;
        }
        
    }
    hour * 100;
    newTime = hour + min;

    return newTime;
 }
Car::CarType Car::StringToEnum(string input){
    if (input == "COMPACT")
    {
        return COMPACT;
    }
    else
    return TRUCK;
        
}