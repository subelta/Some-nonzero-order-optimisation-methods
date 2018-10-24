#include "OptimisedMinimum.h"

double OptimisedMinimum :: dfdx(double x) {
    return 4*x*x*x + 8*x - 32;
}

double OptimisedMinimum :: d2fdx2(double x) {
    return 12*x*x + 8;
}

OptimisedMinimum :: OptimisedMinimum(double leftB, double rightB, double epsilon) {
    a = leftB;
    b = rightB;
    eps = epsilon;
}
double OptimisedMinimum :: fun(double x) {
    return x*x*x*x + 4*x*x - 32*x + 1;
}

double OptimisedMinimum :: tangent() {
    double A = a;
    double B = b;
    double c = (fun(B) - fun(A) + (A * dfdx(A)) - (B * dfdx(B))) / (dfdx(A) - dfdx(B));
    double DFDXc;
    while (abs(dfdx(c)) > eps) {
        DFDXc = dfdx(c);
        if (DFDXc > 0) {
            B = c;
        }
        if (DFDXc < 0) {
            A = c;
        }
        if (DFDXc == 0) {
            return fun(c);
        }
        c = (fun(B) - fun(A) + A * dfdx(A) - B * dfdx(B)) / (dfdx(A) - dfdx(B));
    }
    return c;
}

double OptimisedMinimum :: newtonRaphson() {
   double A = a;
   double c = A - (dfdx(A) / d2fdx2(A));
   while (dfdx(c) > eps) {
       A = c;
       c = A - (dfdx(A) / d2fdx2(A));
   }
   return c;
}

double OptimisedMinimum :: secant() {
    double B = b;
    double A = a;
    double c = B - ((B - A) / (dfdx(B) - dfdx(A)));
    while (dfdx(c) > eps) {
        A = B;
        B = c;
        c = B - ((B - A) / (dfdx(B) - dfdx(A)));
    }
    return c;
}
