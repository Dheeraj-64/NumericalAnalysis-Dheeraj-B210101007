#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    vector<double> x(n);
    vector<vector<double>> y(n, vector<double>(n, 0));

    cout << "Enter data points (x and corresponding y values):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i][0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    cout << "\nFORWARD DIFFERENCE TABLE\n";
    cout << setw(6) << "x" << setw(12) << "y";
    for (int i = 1; i < n; i++)
    {
        cout << setw(10) << "Δ^" << i << "y";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << setw(6) << x[i];
        for (int j = 0; j < n - i; j++)
        {
            cout << setw(12) << y[i][j];
        }
        cout << endl;
    }

    return 0;
}
