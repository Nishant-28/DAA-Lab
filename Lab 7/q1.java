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

import java.util.Scanner;
import java.util.Arrays;

public class q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of matrices: ");
        int n = sc.nextInt();
        int[] p = new int[n + 1];
        int[][] m = new int[n + 1][n + 1];
        int[][] s = new int[n + 1][n + 1];
        System.out.println("Enter row and col size of A1: ");
        p[0] = sc.nextInt();
        p[1] = sc.nextInt();
        for (int i = 2; i <= n; i++) {
            System.out.println("Enter row and col size of A" + i + ": ");
            int r = sc.nextInt();
            int c = sc.nextInt();
            if (p[i - 1] != r) {
                System.out.println("Invalid dimensions");
                System.exit(0);
            }
            p[i] = c;
        }
        for (int i = 0; i <= n; i++) {
            Arrays.fill(m[i], 0);
            Arrays.fill(s[i], 0);
        }
        for (int l = 2; l <= n; l++) {
            for (int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1;
                m[i][j] = Integer.MAX_VALUE;
                for (int k = i; k <= j - 1; k++) {
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j]) {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
        System.out.println("\nM Table:");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                System.out.print(m[i][j] + " ");
            System.out.println();
        }
        System.out.println("\nS Table:");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                System.out.print(s[i][j] + " ");
            System.out.println();
        }
        System.out.println("\nOptimal parenthesization: " + print(s, 1, n));
        System.out.println("The optimal ordering of the given matrices requires " + m[1][n] + " scalar multiplications.");  
        sc.close();
    }

    public static String print(int[][] s, int i, int j) {
        if (i == j)
            return "A" + i;
        else
            return "(" + print(s, i, s[i][j]) + print(s, s[i][j] + 1, j) + ")";
    }

}
