#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){

    int sample[10];

    int t;

    for (t=0; t<10; ++t)
        sample[t] = t;

    for (t=0; t<10; ++t)
        cout << "Index " << t << " Volume: " << sample[t] << "\n";

    int i, avg, min_val, max_val;
    int num[10];

    for (i = 0; i<10; ++i)
        num[i] = rand();
    // AVG
    avg = 0;
    for (i = 0; i<10; ++i)
        avg += num[i];
    avg /= 10;

    cout << "\navg = " << avg << "\n";
    // MIN MAX
    min_val = max_val = num[0];

    for (i = 1; i<10; ++i){
        if (min_val > num[i])
            min_val = num[i];
        if (max_val < num[i])
            max_val = num[i];
    }

    cout << "MIN : " << min_val << "\n";
    cout << "MAX : " << max_val << "\n\n";

    int b[10];

    for (i = 0; i<10; ++i)
        b[i] = num[i];

    for (i = 0; i<10; ++i)
        cout << b[i] << "  " << num[i] << "\n";

    cout << "\n\n";

    return 0;
}
