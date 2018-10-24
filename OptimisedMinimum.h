#ifndef OPTIM_HW2_OPTIMISEDMINIMUM_H
#define OPTIM_HW2_OPTIMISEDMINIMUM_H

#include<iostream>
#include <math.h>

using namespace std;

class OptimisedMinimum {
private:
    double a;
    double b;
    double eps;
    double fib(unsigned int n);
    double dfdx(double x);
    double d2fdx2(double x);

public:
    OptimisedMinimum(double leftB, double rightB, double epsilon);
    double fun(double x);
    double tangent();
    double newtonRaphson();
    double secant();
};

#endif //OPTIM_HW2_OPTIMISEDMINIMUM_H
