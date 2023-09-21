// Write a program to find out the Longest Common Subsequence of two given strings. Calculate length of the LCS.

// Input:
// Enter the first string into an array: 10010101
// Enter the second string into an array: 010110110

// Output:
// LCS: 100110
// LCS Length: 6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    char s1[100], s2[100];
    printf("Enter the first string into an array: ");
    scanf("%s", s1);
    printf("Enter the second string into an array: ");
    scanf("%s", s2);
    int m = strlen(s1);
    int n = strlen(s2);
    int lcs[m + 1][n + 1];
    int i, j;
    for (i = 0; i <= m; i++)
    {
        lcs[i][0] = 0;
    }
    for (j = 0; j <= n; j++)
    {
        lcs[0][j] = 0;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            if (s1[i - 1] == s2[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
        }
    }
    printf("LCS: ");
    int index = lcs[m][n];
    char lcs_string[index + 1];
    lcs_string[index] = '\0';
    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs_string[index - 1] = s1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (lcs[i - 1][j] > lcs[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    printf("%s\n", lcs_string);
    printf("LCS Length: %d\n", lcs[m][n]);
    return 0;
}   
