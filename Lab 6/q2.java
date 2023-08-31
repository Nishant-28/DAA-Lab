// /*Aim of the program: Huffman coding assigns variable length codewords to fixed length input
// characters based on their frequencies or probabilities of occurrence. Given a set of characters
// along with their frequency of occurrences, write a c program to construct a Huffman tree.
// Note#

// • Declare a structure SYMBOL having members alphabet and frequency. Create a Min-
// Priority Queue, keyed on frequency attributes.

// • Create an array of structures where size=number of alphabets.
// Input:
// Enter the number of distinct alphabets: 6
// Enter the alphabets: a b c d e f
// Enter its frequencies: 45 13 12 16 9 5
// Output:
// In-order traversal of the tree (Huffman): a c b f e d */

// import java.util.Scanner;

// class SYMBOL {
//     char alphabet;
//     int frequency;
//     SYMBOL left;
//     SYMBOL right;
// }

// public class q2 {
//     public static void main(String[] args) {
//         try (Scanner sc = new Scanner(System.in)) {
//             System.out.println("Enter the number of distinct alphabets: ");
//             int n = sc.nextInt();
//             SYMBOL[] symbol = new SYMBOL[n];
//             for (int i = 0; i < n; i++) {
//                 symbol[i] = new SYMBOL();
//                 System.out.println("Enter the alphabets: ");
//                 symbol[i].alphabet = sc.next().charAt(0);
//                 System.out.println("Enter its frequencies: ");
//                 symbol[i].frequency = sc.nextInt();
//             }
//             for (int i = 0; i < n; i++) {
//                 for (int j = 0; j < n - (i + 1); j++) {
//                     if (symbol[j].frequency > symbol[j + 1].frequency) {
//                         SYMBOL temp = symbol[j];
//                         symbol[j] = symbol[j + 1];
//                         symbol[j + 1] = temp;
//                     }
//                 }
//             }
//             for (int i = 0; i < n; i++) {
//                 System.out.println(symbol[i].alphabet + " " + symbol[i].frequency);
//             }
//             SYMBOL root = new SYMBOL();
//             root.alphabet = ' ';
//             root.frequency = symbol[0].frequency + symbol[1].frequency;
//             root.left = symbol[0];
//             root.right = symbol[1];
//             for (int i = 2; i < n; i++) {
//                 SYMBOL temp = new SYMBOL();
//                 temp.alphabet = ' ';
//                 temp.frequency = root.frequency + symbol[i].frequency;
//                 temp.left = root;
//                 temp.right = symbol[i];
//                 root = temp;
//             }
//             System.out.println("In-order traversal of the tree (Huffman): ");
//             inorder(root);
//         }
//     }

//     public static void inorder(SYMBOL root) {
//         if (root != null) {
//             inorder(root.left);
//             System.out.print(root.alphabet + " ");
//             inorder(root.right);
//         }
//     }
// }


import java.util.Scanner;

class SYMBOL {
    char alphabet;
    int frequency;
    SYMBOL left;
    SYMBOL right;
}

public class q2 {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter the number of distinct alphabets: ");
            int n = sc.nextInt();
            SYMBOL[] symbol = new SYMBOL[n];
            for (int i = 0; i < n; i++) {
                symbol[i] = new SYMBOL();
                System.out.println("Enter the alphabets: ");
                symbol[i].alphabet = sc.next().charAt(0);
                System.out.println("Enter its frequencies: ");
                symbol[i].frequency = sc.nextInt();
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - (i + 1); j++) {
                    if (symbol[j].frequency > symbol[j + 1].frequency) {
                        SYMBOL temp = symbol[j];
                        symbol[j] = symbol[j + 1];
                        symbol[j + 1] = temp;
                    }
                }
            }
            SYMBOL root = constructHuffmanTree(symbol, n);
            System.out.println("In-order traversal of the tree (Huffman): ");
            inorder(root);
        }
    }

    public static SYMBOL constructHuffmanTree(SYMBOL[] symbol, int n) {
        for (int i = 0; i < n - 1; i++) {
            SYMBOL temp = new SYMBOL();
            temp.alphabet = ' ';
            temp.frequency = symbol[i].frequency + symbol[i + 1].frequency;
            temp.left = symbol[i];
            temp.right = symbol[i + 1];

            // Insert the new node back into the array at the correct position
            int j = i + 2;
            while (j < n && temp.frequency > symbol[j].frequency) {
                symbol[j - 1] = symbol[j];
                j++;
            }
            symbol[j - 1] = temp;
        }
        return symbol[n - 1];
    }

    public static void inorder(SYMBOL root) {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.alphabet + " ");
            inorder(root.right);
        }
    }
}
