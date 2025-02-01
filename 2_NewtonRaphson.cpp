#include<bits/stdc++.h>
using namespace std;

double f(double x) 
{
    return x * x * x - x - 1;
}

double df(double x) 
{
    return 3 * x * x - 1;
}

void NewRaph(double x0, double tol = 1e-6, int maxIterations = 100) 
{
    double x = x0;
    int iteration = 0;

    cout << fixed << setprecision(6);
    cout << "Iteration\tX\t\tf(X)\t\tf'(X)\t\tNew X\n";

    while (iteration < maxIterations) 
    {
        double fx = f(x);
        double dfx = df(x);

        if (abs(dfx) < 1e-9) 
        {
            cout << "Derivative too small, Newton-Raphson may fail.\n";
            return;
        }

        double x_new = x - (fx / dfx);

        cout << iteration + 1 << "\t\t" << x << "\t" << fx << "\t" << dfx << "\t" << x_new << "\n";

        if (abs(x_new - x) < tol) {
            cout << "\nRoot found: " << x_new << " Aprox.\n";
            return;
        }

        x = x_new;
        iteration++;
    }

    cout << "Newton-Raphson method did not converge within " << maxIterations << " iterations.\n";
}

int main() 
{
    double Xo;
    cin >> Xo;

    NewRaph(Xo);

    return 0;
}
