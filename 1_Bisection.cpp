#include<bits/stdc++.h>
using namespace std;

double f(double x) 
{
    return x * x * x - x - 1;
}

void Bisection(double a, double b, double tol) 
{
    if (f(a) * f(b) >= 0) 
    {
        cout << "The function has the same sign at the endpoints of the interval." << endl;
        return;
    }

    double c = a; 
    while ((b - a) >= tol) 
    {
        c = (a + b) / 2; 

        cout << "a: " << a << ", b: " << b << ", c: " << c << ", f(c): " << f(c) << endl;

        if (f(c) == 0.0) 
        {
            break;
        }

        if (f(c) * f(a) < 0) 
        {
            b = c;
        } 
        else 
        {
            a = c;
        }
    }

    cout << "The root is approximately: " << c << endl;
}

int main() 
{
    double a, b, tol;

    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;

    cout << "Enter the tolerance: ";
    cin >> tol;

    Bisection(a, b, tol);

    return 0;
}
