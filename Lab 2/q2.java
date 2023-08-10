import java.io.*;
import java.util.Scanner;

public class InsertionSort {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        // Create a menu for the user to choose from
        System.out.println("MAIN MENU (INSERTION SORT)");
        System.out.println("1. Ascending Data");
        System.out.println("2. Descending Data");
        System.out.println("3. Random Data");
        System.out.println("4. ERROR (EXIT)");

        // Get the user's choice
        int choice = scanner.nextInt();

        // Read the data from the input file
        File inputFile;
        String outputFile;
        switch (choice) {
            case 1:
                inputFile = new File("inAsce.dat");
                outputFile = "outInsAsce.dat";
                break;
            case 2:
                inputFile = new File("inDesc.dat");
                outputFile = "outInsDesc.dat";
                break;
            case 3:
                inputFile = new File("inRand.dat");
                outputFile = "outInsRand.dat";
                break;
            default:
                System.out.println("Invalid choice.");
                return;
        }
        Scanner inputScanner = new Scanner(inputFile);
        int[] data = new int[inputScanner.nextInt()];
        for (int i = 0; i < data.length; i++) {
            data[i] = inputScanner.nextInt();
        }
        inputScanner.close();

        // Sort the data using insertion sort
        int comparisons = 0;
        int[] sortedData = insertionSort(data, comparisons);

        // Write the sorted data to the output file
        PrintWriter outputWriter = new PrintWriter(outputFile);
        for (int i = 0; i < sortedData.length; i++) {
            outputWriter.println(sortedData[i]);
        }
        outputWriter.close();

        // Display the sorted data to the console
        System.out.println("Before Sorting:");
        for (int i = 0; i < data.length; i++) {
            System.out.println(data[i]);
        }
        System.out.println("After Sorting:");
        for (int i = 0; i < sortedData.length; i++) {
            System.out.println(sortedData[i]);
        }
        System.out.println("Number of Comparisons: " + comparisons);

        // Determine if the input scenario is best or worst case
        if (comparisons == 0) {
            System.out.println("Scenario: Best Case");
        } else if (comparisons == (data.length * (data.length - 1)) / 2) {
            System.out.println("Scenario: Worst Case");
        } else {
            System.out.println("Scenario: General Case");
        }
    }

    public static int[] insertionSort(int[] data, int comparisons) {
        for (int i = 1; i < data.length; i++) {
            int key = data[i];
            int j = i - 1;
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
                comparisons++;
            }
            data[j + 1] = key;
        }
        return data;
    }
}
