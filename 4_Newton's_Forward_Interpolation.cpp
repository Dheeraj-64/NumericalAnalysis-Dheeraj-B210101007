#include <bits/stdc++.h>
using namespace std;

void forwardDifferenceTable(vector<vector<double>>& a, int n) 
{
    for (int j = 1; j < n; j++) 
    {
        for (int i = 0; i < n - j; i++) 
        {
            a[i][j] = a[i + 1][j - 1] - a[i][j - 1];
        }
    }
}

double newtonForwardInterpolation(vector<vector<double>>& a, double x, int n) 
{
    double h = a[1][0] - a[0][0]; 
    double u = (x - a[0][0]) / h;   
    double y = a[0][1];          

    double term = 1.0;
    for (int i = 1; i < n; i++) 
    {
        term *= (u - (i - 1)); 
        y += (term * a[0][i]) / tgamma(i + 1); 
    }
    return y;
}

int main() 
{
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n + 1, 0));

    cout << "Enter x values: ";
    for (int i = 0; i < n; i++) cin >> a[i][0]; 

    cout << "Enter corresponding y values: ";
    for (int i = 0; i < n; i++) cin >> a[i][1]; 

    forwardDifferenceTable(a, n);

    cout << "\nForward Difference Table:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << setw(6) << a[i][0] << " ";
        for (int j = 1; j < n - i + 1; j++) 
        {
            cout << setw(12) << a[i][j] << " ";
        }
        cout << endl;
    }

    double x;
    cout << "\nEnter value of x for which you want to find y: ";
    cin >> x;

    double result = newtonForwardInterpolation(a, x, n);
    cout << "Interpolated value at x = " << x << " is: " << fixed << setprecision(6) << result << endl;

    return 0;
}
