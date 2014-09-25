#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x,y,z;

    x = 5;
    y = 4;

    z = sqrt(x*x+y*y);

    cout << "z = " << z ;

    cout << "\n" ;

    double distance = 34000000.0;
    double lightspeed = 186000.0;
    double delay;
    double delay_in_min;

    delay = distance/lightspeed ;

    cout << "delay " << delay << " secon_d.\n";

    delay_in_min = delay / 60.0;

    cout << "it's " << delay_in_min << " min";

    return 0;
}
