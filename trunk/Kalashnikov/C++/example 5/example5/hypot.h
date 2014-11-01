#ifndef HYPOT_H
#define HYPOT_H
#include <math.h>

double hypot(double a, double b){

    double result = sqrt (a*a+b*b);

    return result;
}

#endif // HYPOT_H
