
#include <iostream>

using namespace std;

class Vihicle {
public:
    int passengers; // pas
    int fuelcup; // l

    int mpg; // on km
};

int main()
{
    Vihicle minivan; // the object

    int range;

    minivan.passengers = 7;
    minivan.fuelcup = 16;
    minivan.mpg = 21;

    range = minivan.fuelcup * minivan.mpg;

    cout << "Minivan can transport " << minivan.passengers << " on " << range << " km. \n";

    return 0;
}
