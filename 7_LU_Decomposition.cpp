#include <bits/stdc++.h>
using namespace std;

void LU_Decomposition(vector<vector<double>> &A, vector<vector<double>> &L, vector<vector<double>> &U, int n) {
    for (int i = 0; i < n; i++) 
    {
        for (int k = i; k < n; k++) 
        {
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += (L[i][j] * U[j][k]);
            U[i][k] = A[i][k] - sum;
        }

        for (int k = i; k < n; k++) 
        {
            if (i == k) L[i][i] = 1; 
            else 
            {
                double sum = 0;
                for (int j = 0; j < i; j++) sum += (L[k][j] * U[j][i]);
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

vector<double> forwardSubstitution(vector<vector<double>> &L, vector<double> &B, int n) 
{
    vector<double> Y(n);
    for (int i = 0; i < n; i++) 
    {
        double sum = 0;
        for (int j = 0; j < i; j++)
            sum += L[i][j] * Y[j];
        Y[i] = (B[i] - sum);
    }
    return Y;
}

vector<double> backwardSubstitution(vector<vector<double>> &U, vector<double> &Y, int n) 
{
    vector<double> X(n);
    for (int i = n - 1; i >= 0; i--) 
    {
        double sum = 0;
        for (int j = i + 1; j < n; j++) sum += U[i][j] * X[j];
        X[i] = (Y[i] - sum) / U[i][i];
    }
    return X;
}

int main() 
{
    int n;
    cout << "Enter number of variables: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> B(n);
    vector<vector<double>> L(n, vector<double>(n, 0)), U(n, vector<double>(n, 0));

    cout << "Enter coefficient matrix (A):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> A[i][j];

    cout << "Enter constant terms (B):\n";
    for (int i = 0; i < n; i++)
        cin >> B[i];

    LU_Decomposition(A, L, U, n);

    cout << "\nLower Triangular Matrix (L):\n";
    for (const auto &row : L) {
        for (double val : row)
            cout << setw(8) << setprecision(4) << val << " ";
        cout << endl;
    }

    cout << "\nUpper Triangular Matrix (U):\n";
    for (const auto &row : U) {
        for (double val : row)
            cout << setw(8) << setprecision(4) << val << " ";
        cout << endl;
    }

    vector<double> Y = forwardSubstitution(L, B, n);

    vector<double> X = backwardSubstitution(U, Y, n);

    cout << "\nSolution (X):\n";
    for (int i = 0; i < n; i++)
        cout << "x[" << i << "] = " << fixed << setprecision(6) << X[i] << endl;

    return 0;
}
