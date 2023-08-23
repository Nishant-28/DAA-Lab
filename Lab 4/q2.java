import java.io.*;
import java.util.*;

public class q2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            System.out.println("MAIN MENU (QUICK SORT)");
            System.out.println("1. Ascending Data");
            System.out.println("2. Descending Data");
            System.out.println("3. Random Data");
            System.out.println("4. EXIT");
            
            System.out.print("Enter option: ");
            int option = scanner.nextInt();
            
            if (option == 4) {
                System.out.println("Exiting...");
                break;
            }
            
            String inputFile, outputFile, scenario;
            if (option == 1) {
                inputFile = "inAsce.dat";
                outputFile = "outQuickAsce.dat";
                scenario = "Ascending";
            } else if (option == 2) {
                inputFile = "inDesc.dat";
                outputFile = "outQuickDesc.dat";
                scenario = "Descending";
            } else if (option == 3) {
                inputFile = "inRand.dat";
                outputFile = "outQuickRand.dat";
                scenario = "Random";
            } else {
                System.out.println("Invalid option. Please choose a valid option.");
                continue;
            }
            
            int[] arr = readFromFile(inputFile);
            
            System.out.println("Before Sorting: " + Arrays.toString(arr));
            
            int comparisons = quickSort(arr, 0, arr.length - 1);
            
            writeToFile(outputFile, arr);
            
            System.out.println("After Sorting: " + Arrays.toString(arr));
            System.out.println("Number of Comparisons: " + comparisons);
            System.out.println("Scenario: " + determineScenario(arr.length, comparisons));
        }
    }
    
    public static int[] readFromFile(String fileName) {
        try (Scanner scanner = new Scanner(new File(fileName))) {
            List<Integer> list = new ArrayList<>();
            while (scanner.hasNextInt()) {
                list.add(scanner.nextInt());
            }
            return list.stream().mapToInt(Integer::intValue).toArray();
        } catch (FileNotFoundException e) {
            System.out.println("File not found: " + fileName);
            return new int[0];
        }
    }
    
    public static void writeToFile(String fileName, int[] arr) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(fileName))) {
            for (int num : arr) {
                writer.print(num + " ");
            }
        } catch (IOException e) {
            System.out.println("Error writing to file: " + fileName);
        }
    }
    
    public static int quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            int comparisonsLeft = quickSort(arr, low, pivotIndex - 1);
            int comparisonsRight = quickSort(arr, pivotIndex + 1, high);
            return comparisonsLeft + comparisonsRight + (high - low);
        }
        return 0;
    }
    
    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return i + 1;
    }
    
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    public static String determineScenario(int n, int comparisons) {
        int bestCaseComparisons = (n * (n - 1)) / 2;
        if (comparisons == bestCaseComparisons) {
            return "Best-case";
        } else if (comparisons == n - 1) {
            return "Worst-case";
        } else {
            return "Average-case";
        }
    }
}
