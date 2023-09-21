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


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    int p[n + 1];
    int i, j, k, l, q;
    for (i = 0; i <= n; i++)
    {
        printf("Enter row and col size of A%d: ", i);
        scanf("%d %d", &p[i], &p[i + 1]);
    }
    int m[n + 1][n + 1];
    int s[n + 1][n + 1];
    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("\nM Table:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
    printf("\nS Table:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", s[i][j]);
        printf("\n");
    }
    printf("\nOptimal parenthesization: ");
    printf("( ");
    printParenthesis(s, 1, n);
    printf(")");
    printf("\nThe optimal ordering of the given matrices requires %d scalar multiplications.\n", m[1][n]);
    return 0;
}

void printParenthesis(int s[][100], int i, int j)
{
    if (i == j)
        printf("A%d ", i);
    else
    {
        printf("( ");
        printParenthesis(s, i, s[i][j]);
        printParenthesis(s, s[i][j] + 1, j);
        printf(") ");
    }
}
