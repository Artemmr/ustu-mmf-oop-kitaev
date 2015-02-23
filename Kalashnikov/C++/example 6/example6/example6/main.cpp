#include <iostream>
#include <cstring>

using namespace std;

double reciprocal (double x); /// обратное значение
void swap (int &x, int &y); /// Vengeful spirit
void f (int &i); /// Пример ссылочного параметра
double &z ();
double &change_it (int i);
void function (int i);
void function (int i, int j);
void function (double k);
void mystrcat (char *s1, char *s2, int len = 0);

double val2 = 100.0;
double vals[] = {1.1, 2.2, 3.3, 4.4, 5.5};



int main(){
/*
    double t = 10.0;

    cout << "this: " << reciprocal(t) << "\n";
    cout << "value t: " << t << "\n";

    int l=10, m=20;

    cout << "l: " << l << " & m: " << m << "\n";

    swap(l,m);

    cout << "l: " << l << " & m: " << m << "\n";

    int val = 1;

    cout << "val: " << val << "\n" ;

    f (val);

    cout << "val: " << val << "\n" ;

    t = val2;

    cout << z() << "\n";

    z() = 99.1;

    cout << z() << "\n";
    cout << "Исходны массив";

    for ( int i = 0; i < 5; i++)
        cout << vals[i] << " ";
    cout << "\n";

    change_it(1) = 5298.23;
    change_it(3) = -98.8;
    vals[4] = 100500;

    cout << "End " << "\n";

    for (int i = 0; i < 5; i++)
        cout << vals[i] << " ";
    cout << "\n";

    function(10);
    function(10,20);
    function(10.23);

    char str1[80] = "test";
    char str2[80] = "133329";

    mystrcat(str1, str2, 4);

    cout << str1 << "\n";

    strcpy(str1, "test");

    mystrcat(str1, str2);

    cout << str1 << "\n";

    return 0;
}

void f (int &i){
    i = 10;
}


double reciprocal(double x){
    x = 1/x;

    return x;
}

void swap (int &x, int &y){

    int temp;

    temp = x;

    x = y;

    y = temp;
}

double &z () {

    return val2;
}

double &change_it (int i){

    return vals[i];
}

void function(int i){

    cout << "f(int i) : " << i << "\n";
}

void function(int i, int j){

    cout << "f(int i, int j) : " << i << " " << j << "\n";
}

void function(double k){

    cout << "f(double k) : " << k << "\n";
}

void mystrcat(char *s1, char *s2, int len){

    while (*s1)
        s1++;

    if (len == 0)
        len = strlen(s2);

    while (*s2 && len) {

        *s1 = *s2;
        s1++;
        s2++;
        len--;
    }

    *s1 = '\0';
}
*/



    return 0;
}
