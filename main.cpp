#include <iostream>
#include "OptimisedMinimum.h"

using namespace std;

int main() {
    double a, b, eps;
    cout << "Define the segment by inputing 2 positive numbers a and b (a <= b):" << endl;
    cin >> a >> b;
    cout << "Input Epsilon:" << endl;
    cin >> eps;
    OptimisedMinimum myConstrait(a, b, eps);
    cout << "Tangent method: x(min) = " << myConstrait.tangent() << endl;
    cout << "Newton - Raphson method: x(min) = " << myConstrait.newtonRaphson() << endl;
    cout << "Secant method: x(min) = " << myConstrait.secant() << endl;
    return 0;
}