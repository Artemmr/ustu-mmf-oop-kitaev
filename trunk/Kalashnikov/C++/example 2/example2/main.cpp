 #include <iostream>
#include <cmath>

using namespace std;

int main()
{
    /*
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
/*
    int i;

    for (i=1; i <= 10; i++)
        cout << i << " / 2   is " << (float) i/2 << "\n";

    //Payment

    double Principal;
    double IntRate;

    double PayPerYear;
    double NumYears;
    double numer, denom;

    cout << "Enter: Principal,IntRate,PayPerYear,NumYears";

    cin >> Principal;
    cin >> IntRate;
    cin >> PayPerYear;
    cin >> NumYears;

    numer = IntRate * Principal / PayPerYear ;

    e = - (PayPerYear * NumYears);
    b = (IntRate / PayPerYear) + 1;



    //Pow()
*/
    /*
     * 1. int , long int, shot int, unsigned int, unsigned shot int, unsigned long int
     *
     * 2. float == logn int , just long.
     *
     * 3. true,false
     *
     * 4. Z : ~-65k <= Z <= ~65k
     *
     * 5. \t \a  /// lol , b signall?
     * */

    /*int i;
     cout << "\a signall?"; // work
     cin >> i;
     cout << "\b signall?"; // Don't work, lol! :)
     cin >> i;
     /*
     *
     * 6. Y
     *
     * 7. lol 1-F
     *
     * 8. type var = volue;
     *
     * 9.
     *
 0000011   */
    int i,j,k;

    // first 100
    for (i=0; i<=100; i++){
        k = 0.0;
        for (j=1; j<=i; j++){
            if (i % j == 0)
                k++;
        }
        if (k == 2)
            cout << i << " example number\n";
    }

    return 0;
}
