#include <bits/stdc++.h>
using namespace std;

void gaussElimination(vector<vector<double>> &a, vector<double> &b, int n) 
{

    for (int i = 0; i < n; i++) 
    {
        for (int k = i + 1; k < n; k++) 
        {
            double factor = a[k][i] / a[i][i];
            for (int j = i; j < n; j++) 
            {
                a[k][j] -= factor * a[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) 
    {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) 
        {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << "x[" << i << "] = " << fixed << setprecision(6) << x[i] << endl;
    }
}

int main() 
{
    int n;
    cout << "Enter number of variables: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n)); 
    vector<double> b(n); 

    cout << "Enter the augmented matrix (coefficients and right-hand side values):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> a[i][j];
        }
        cin >> b[i];
    }

    gaussElimination(a, b, n);

    return 0;
}
