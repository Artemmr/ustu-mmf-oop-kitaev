#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    int magic;
    int guess;

    magic = rand();

    cout << "Enter number: ";
    cin >> guess;

    if (guess == magic)
        cout << "** Yep **\n";
    else {
        cout << "so sorry...\n";
        if (guess > magic)
            cout << "number > magic number\n";
        else
            cout << "number < magic number\n";
    }

    int a;
    int b;

    cout << "So, a / b \nPls, enter number a: ";
    cin >> a;
    cout << "Pls, enter number b: ";
    cin >> b;

    if (b)
        cout << (((double) a) / ((double) b));
    else
        cout << "Pls don't do it\n";

    int num;

    cout << "\ncenter one or two or three : ";
    cin >> num;

    switch (num) {
        case 1:
            cout << "1\n";
            break;
        case 2:
            cout << "2\n";
            break;
        case 3:
            cout << "3\n";
            break;
        default:
            cout << "1 or 2 or 3, pls.\n";
    }

    int choice;

    cout << "\nHelp: \n";
    cout << "1. if\n";
    cout << "2. switch\n";
    cout << "Enter number: ";

    cin >> choice;

    switch (choice) {
        case 1:
            cout << "1. help for if\n";
            break;
        case 2:
            cout << "2. help for switch\n";
            break;
        default:
            cout << "wtf? 1 or 2, pls!\n";
    }

    int i = 0;
    cout << "\n";
    for (i = 50; i >= -50; i = i -10) cout << i << ' ';
    cout << "\n";

    /*for (int count = 10; cout < 5; count++)
            cout << count;
    */

    int x,y;

    for (x=0, y=10; x <= y; ++x, --y){
        cout << x << " " << y << "\n";
    }

    unsigned int r;

    r = (unsigned int) rand();

    for (i=1; r >= 2000; i++) {
        r = rand();
    }

    cout << "Mission complite!" << " i = " << i << "     r = " << r << "\n";

    int sum = 0;

    for (i = 1; i <= 10; sum += i++ );

    cout << "Summ: " << sum << "\n";

    int fact = 1;
    sum = 0;
    i = 0;

    for (int i = 1; i <= 5; i++ ){
        sum += i;
        fact *= i;
    }

    cout << "Summ: " << sum << "\n";
    cout << "Fact: " << fact << "\n";
    cout << "i " << i << "\n";

    return 0;
}
