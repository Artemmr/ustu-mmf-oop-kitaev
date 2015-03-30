
#include <iostream>

using namespace std;

class Vehicle {
public:
    int passengers; // pas
    int fuelcap; // l
    int mpg; // on km

    int range();
};

int main()
{
    Vehicle minivan; // the object
    Vehicle sportcar;

//    int range;

    minivan.passengers = 7;
    minivan.fuelcap = 16;
    minivan.mpg = 21;

    sportcar.passengers = 2;
    sportcar.fuelcap = 14;
    sportcar.mpg = 12;

//    range = minivan.fuelcap * minivan.mpg;
    cout << "Minivan can transport " << minivan.passengers << " on " << minivan.range() << " km. \n";

//    range = sportcar.fuelcap * sportcar.mpg;
    cout << "Sportcar can transport " << sportcar.passengers << " on " << sportcar.range() << " km. \n";

    return 0;
}

int Vehicle::range(){
    return fuelcap*mpg;
}
