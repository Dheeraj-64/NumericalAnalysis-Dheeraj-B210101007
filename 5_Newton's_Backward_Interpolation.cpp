#include <bits/stdc++.h>
using namespace std;

void backwardDifferenceTable(double y[][10], int n) 
{
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }
}

double newtonsBackwardInterpolation(double x[], double y[][10], int n, double value) 
{
    double h = x[1] - x[0];   
    int i = n - 1;             
    double u = (value - x[n - 1]) / h; 
    double sum = y[n - 1][0];       

    double term = 1.0;  
    for (int j = 1; j < n; j++) 
    {
        term *= (u + j - 1); 
        sum += (term * y[n - 1][j]) / factorial(j); 
    }

    return sum;
}

double factorial(int n) 
{
    double fact = 1;
    for (int i = 2; i <= n; i++) 
    {
        fact *= i;
    }
    return fact;
}

int main() 
{
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n][10];   
    
    cout << "Enter x values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    cout << "Enter corresponding y values: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> y[i][0];  
    }

    backwardDifferenceTable(y, n);

    cout << "\nBackward Difference Table:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << setw(6) << x[i] << " ";
        for (int j = 0; j < n - i; j++) {
            cout << setw(12) << y[i][j] << " ";
        }
        cout << endl;
    }

    double value;
    cout << "\nEnter value to interpolate: ";
    cin >> value;

    double result = newtonsBackwardInterpolation(x, y, n, value);
    cout << "Interpolated value at x = " << value << " is: " << fixed << setprecision(6) << result << endl;

    return 0;
}
