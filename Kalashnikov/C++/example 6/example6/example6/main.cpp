#include <iostream>

using namespace std;

double reciprocal (double x); /// обратное значение
void swap (int &x, int &y); /// Vengeful spirit
void f (int &i); /// Пример ссылочного параметра

int main(){

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
