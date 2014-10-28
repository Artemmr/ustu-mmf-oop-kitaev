#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cctype>

//#include <sqrs.h>

using namespace std;

int square[][2] = { // инициализация массива
    {1, 1},
    {2, 4},
    {3, 9},
    {4, 16},
    {5, 25},
    {6, 36},
    {7, 49},
    {8, 64},
    {9, 81},
    {10, 100}
};

int main(){
/*
    int sample[10];

    int t;

    for (t=0; t<10; ++t)
        sample[t] = t;

    for (t=0; t<10; ++t)
        cout << "Index " << t << " Volume: " << sample[t] << "\n";

    int avg, min_val, max_val;
    int num[10];

    for (int i = 0; i<10; ++i)
        num[i] = rand();
    // AVG
    avg = 0;
    for (int i = 0; i<10; ++i)
        avg += num[i];
    avg /= 10;

    cout << "\navg = " << avg << "\n";
    // MIN MAX
    min_val = max_val = num[0];

    for (int i = 1; i<10; ++i){
        if (min_val > num[i])
            min_val = num[i];
        if (max_val < num[i])
            max_val = num[i];
    }

    cout << "MIN : " << min_val << "\n";
    cout << "MAX : " << max_val << "\n\n";

    int b[10];

    for (int i = 0; i<10; ++i)
        b[i] = num[i];

    for (int i = 0; i<10; ++i)
        cout << b[i] << "  " << num[i] << "\n";

    cout << "\n\n";

    int nums [3][4];

    for (int t=0; t < 3; ++t){
        for(int i=0; i < 4; ++i){
            nums [t][i] = (t*4) + i + 1;
            cout << nums [t][i] << " " ;
        }
        cout << "\n";
    }

    int nums1[10];
    int a1, b1, t1;
    int size1;

    size1 = 10;

    srand(911);

    for (t1 = 0; t1 < size1; t1++)
        nums1[t1] = rand();

    cout << "start array:\n";

    for (t1 = 0; t1 < size1; t1++)
        cout << nums1[t1] << "  ";

    cout << '\n';

    for (a1 = 1; a1 < size1; a1++){
        for (b1 = size1-1; b1 >= a1; b1--) {
            if (nums1[b1-1] > nums1[b1]){
                t1 = nums1[b1-1];
                nums1[b1-1] = nums1[b1];
                nums1[b1] = t1;
            }
        }
    }

    cout << "after array: \n";

    for (t1 = 0; t1 < size1; t1++)
        cout << nums1[t1] << "  ";

    cout << "\n\n";

//    char str[80];

//    cout << "Enter string: ";
//    cin >>  str;

//    cout << "U string: ";
//    cout << str;

//    cout << "\n\n";

    char rome[90];

    cout << "\npls, enter txt: ";

    gets(rome);


    cout << "U string: ";
    cout << rome;

    cout << "\n\n";

    char s1[80], s2[80];

    strcpy(s1, "C++");
    strcpy(s2, " be cool");

    cout << "Length string: " << strlen(s1);
    cout << " " << strlen(s2) << "\n";

    if (!strcmp(s1,s2))
        cout << "good";
    else
        cout << "bad";

    cout << "\n";

    strcat(s1,s2);
    cout << s1 << "\n";

    strcpy(s2,s1);
    cout << s1 << " and " << s2 << "\n";

    if (!strcmp(s1,s2))
        cout << "s1 == s2\n";

    char str[80];

    int i;

    strcpy(str, "aFFFf");

    for (i=0; str[i]; i++)
        str[i] = tolower(str[i]);

    cout << str << "\n";

    cout << "\n";

    char roms[7] = "dsfs";

    cout << "it's 4 el: " << roms[0];

    cout << "\n\npls, enter first number 1..10: ";

    int first,p;

    cout << "\n\nEnter number 0..10: ";

    first = 9;

    for (p = 0; p < 10; p++){

        if (square[p][0] == first)
            break;
    }

    cout << "kvadrat bydet: " << square[p][1];

    cout << "\n\n";
    ////////////////
    int i;

    char str1[80] = {"E"};

    char numbers[10][80] = {
        "A","111",
        "B","222",
        "C","333",
        "D","444",
        "E","555",
    };

    cout << "isalpha?: ";

    for (i = 0; i < 10; i += 2){
        if (!strcmp(str1,numbers[i])){
            cout << "Tel: " << numbers[i+1] << "\n";
            break;
        }
        if (i == 9)
            cout << "Error, sry!";
    }
    cout << "\n";

    //int list[] = {1,2,3,4};

    //char str[] = "Hi";

    //int nums[] = {44,55,66,77};

    int total;
    int *ptr;
    int val;

    total = 3200; //
    ptr = &total;
    val = *ptr;

    cout << "total = " << val << "\n";

    int *z, num;

    z = &num;

    *z = 100;

    cout << num << " ";
    (*z)++;

    cout << num << " ";
    (*z)--;

    cout << *z << "\n\n";

    int *i, j[10];

    double *f, g[10];

    int x;

    i = j;
    f = g;

    for (x = 0; x < 10; x++)
        cout << i+x << ' ' << f+x << "\n\n";

    int k;

    char str[80] = "This Is A Street";

    cout << "U str: " << str << "\n";

    for (k = 0; str[k]; k++){
        if (isupper(str[k]))
            str[k] = tolower(str[k]);
        else if (islower(str[k]))
            str[k] = toupper(str[k]);
    }

    cout << "Our str: " << str << "\n";

    char *p;

    p = str;

    while (*p){
        if (isupper(*p))
            *p = tolower(*p);
        else if (islower(*p))
            *p = toupper(*p);
        p++;
    }

    cout << "and now: " << str << "\n";

    char *p;
    int i;
    char str[80] = "This is street";

    cout << "U string" << str << "\n";

    p = str;

    for (i = 0; p[i]; i++){
        if(isupper(p[i]))
            p[i] = tolower(p[i]);
        else if (islower(p[i]))
            p[i] = toupper(p[i]);
    }

    cout << "Our str:" << str << "\n\n";


    char *ptr;

    ptr = "Work!\n";

    cout << ptr;

    cout << "\n";

    char str[] = "It's easy!";

    char *start, *end;

    int len;

    char t;

    cout << "U str: " << str << "\n";

    len = strlen(str);

    start = str;
    end = &str[len-1];

    while (start < end) {
        t = *start;
        *start = *end;
        *end = t;

        end--;
        start++;
    }

    cout << "Our str: " << str << "\n";

    int x, *p, **q;

    x = 10;

    p = &x;

    q = &p;

    cout << **q << "end,\n\n";


    //1 short int hightemps[32];

    //2 определение тип

    int num[10];

    for (int i = 0; i < 10; i++){// array numbers [10]
        cout << "Pls, enter the num: ";
        cin >> num[i];
    }

    for (int i = 0; i < 10; i++){
        for (int j = i+1; j < 10; j++)
            if (num[i] == num[j])
                cout << i << " & " << j << " error!\n";
    }


    //массив эелемнтов типа чар/строковая константа

    char a[80];
    char b[80];
    char *p1, *p2;

    cout << "Pls, enter str \"a\": ";
    cin >> a;

    cout << "Pls, enter str \"b\": ";
    cin >> b;

    p1 = &a[0];
    p2 = &b[0];

    while (!*p1 && !*p2) {
        if (tolower(*p1) != tolower(*p2))
            break;
        else {
            p1++;
            p2++;
        }
    }

    if (!*p1 && !*p2)
        cout << "No";
    else
        cout << "Yep";

    //6 booth

    //7 [][][][];

    //8 int nums[] = {5, 66, 88};

    //9

    //10

    //11

    char str[80];

    int count = 0;

    cout << "enter str: ";
    cin >> str;

    for (int i = 0; str[i]; i++){
        if (isupper(str[i]))
            count++;
    }

    cout << "count :" << count << "\n";
*/
    return 0;
}

















