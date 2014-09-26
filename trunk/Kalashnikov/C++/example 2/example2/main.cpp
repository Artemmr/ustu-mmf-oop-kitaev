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

    bool q,p;

    q = true;
    p = true;

    cout << "\n";
    cout << p << " XOR " << q << " is " << ((p || q) && !(p && q)) << "\n";

    q = true;
    p = false;

    cout << p << " XOR " << q << " is " << ((p || q) && !(p && q)) << "\n";

    q = false;
    p = true;

    cout << p << " XOR " << q << " is " << ((p || q) && !(p && q)) << "\n";

    q = false;
    p = false;

    cout << p << " XOR " << q << " is " << ((p || q) && !(p && q)) << "\n";

    //type cast

    int i;

    for (i=1; i <= 10; i++){
        cout << i << " / 2   is " << (float) i/2 << "\n";

    //Payment

    double Principal;
    double IntRate;

    double PayPerYear;
    double NumYears;
    double numer, denom;

    //Pow()

    }

    return 0;
}
