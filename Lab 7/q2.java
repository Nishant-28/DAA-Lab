
import java.util.Scanner;

public class q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the first string into an array: ");
        String s1 = sc.nextLine();
        System.out.print("Enter the second string into an array: ");
        String s2 = sc.nextLine();
        int m = s1.length();
        int n = s2.length();
        int[][] lcs = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
            lcs[i][0] = 0;
        for (int j = 0; j <= n; j++)
            lcs[0][j] = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                lcs[i][j] = (s1.charAt(i - 1) == s2.charAt(j - 1)) ? lcs[i - 1][j - 1] + 1
                        : Math.max(lcs[i - 1][j], lcs[i][j - 1]);
        System.out.print("LCS: ");
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (s1.charAt(i - 1) == s2.charAt(j - 1))
                System.out.print(s1.charAt(i - 1));
            if (lcs[i - 1][j] > lcs[i][j - 1])
                i--;
            else
                j--;
        }
        System.out.println();
        System.out.println("LCS Length: " + lcs[m][n]);
        sc.close();
    }
}

