// Write a program to implement the matrix chain multiplication problem using M-table & S-table to find optimal parenthesization of a matrix-chain product. Print the number of scalar multiplications required for the given input.
// Note# Dimensions of the matrices can be inputted as row and column values. Validate the dimension compatibility.

// Input:
// Enter number of matrices: 4
// Enter row and col size of A1: 30 35
// Enter row and col size of A2: 35 15
// Enter row and col size of A3: 15 5
// Enter row and col size of A4: 5 10

// Output:

// M Table:
// 0 15750 7875 9375
// 0 0 2625 4375
// 0 0 0 750
// 0 0 0 0

// S Table:
// 0 1 1 3
// 0 0 2 3
// 0 0 0 3
// 0 0 0 0 

// Optimal parenthesization: ( ( A1 (A2 A3)) A4)
// The optimal ordering of the given matrices requires 9375 scalar multiplications.


#include <iostream>
#include <climits>
using namespace std;

void printOptimalParens(int **s, int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void matrixChainOrder(int *p, int n)
{
    int **m = new int *[n];
    int **s = new int *[n];
    for (int i = 0; i < n; i++)
    {
        m[i] = new int[n];
        s[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
        m[i][i] = 0;

    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "M Table:\n";
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }

    cout << "\nS Table:\n";
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
            cout << s[i][j] << " ";
        cout << endl;
    }

    cout << "\nOptimal parenthesization: ";
    printOptimalParens(s, 1, n - 1);
    cout << "\nThe optimal ordering of the given matrices requires " << m[1][n - 1] << " scalar multiplications.\n";
}

int main()
{
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    int *p = new int[n + 1];
    cout << "Enter row and col size of A1: ";
    cin >> p[0] >> p[1];
    for (int i = 2; i <= n; i++)
    {
        cout << "Enter row and col size of A" << i << ": ";
        cin >> p[i - 1] >> p[i];
    }
    matrixChainOrder(p, n + 1);
    return 0;
}
