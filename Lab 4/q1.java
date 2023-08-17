import java.io.*;
import java.util.*;
import java.util.concurrent.TimeUnit;

public class MergeSortMenu {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean exit = false;
        
        while (!exit) {
            System.out.println("MAIN MENU (MERGE SORT)");
            System.out.println("1. Ascending Data");
            System.out.println("2. Descending Data");
            System.out.println("3. Random Data");
            System.out.println("4. Exit");
            System.out.print("Enter option: ");
            
            int option = scanner.nextInt();
            
            switch (option) {
                case 1:
                    performMergeSort("inAsce.dat", "outMergeAsce.dat");
                    break;
                case 2:
                    performMergeSort("inDesc.dat", "outMergeDesc.dat");
                    break;
                case 3:
                    performMergeSort("inRand.dat", "outMergeRand.dat");
                    break;
                case 4:
                    exit = true;
                    break;
                default:
                    System.out.println("Invalid option. Please choose a valid option.");
            }
        }
        
        System.out.println("Exiting...");
    }
    
    public static void performMergeSort(String inputFile, String outputFile) {
        try {
            ArrayList<Integer> data = readFromFile(inputFile);
            
            long startTime = System.nanoTime();
            long comparisons = mergeSort(data, 0, data.size() - 1);
            long endTime = System.nanoTime();
            
            writeToFile(outputFile, data);
            
            System.out.println("Before Sorting: " + data);
            System.out.println("After Sorting: " + data);
            System.out.println("Number of Comparisons: " + comparisons);
            System.out.println("Execution Time: " + (endTime - startTime) + " nanoseconds");
        } catch (IOException e) {
            System.out.println("Error reading/writing file: " + e.getMessage());
        }
    }
    
    public static ArrayList<Integer> readFromFile(String fileName) throws IOException {
        ArrayList<Integer> data = new ArrayList<>();
        BufferedReader reader = new BufferedReader(new FileReader(fileName));
        String line;
        
        while ((line = reader.readLine()) != null) {
            String[] tokens = line.split(" ");
            for (String token : tokens) {
                data.add(Integer.parseInt(token));
            }
        }
        
        reader.close();
        return data;
    }
    
    public static void writeToFile(String fileName, ArrayList<Integer> data) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(fileName));
        for (int num : data) {
            writer.write(num + " ");
        }
        writer.close();
    }
    
    public static long mergeSort(ArrayList<Integer> arr, int left, int right) {
        long comparisons = 0;
        
        if (left < right) {
            int mid = (left + right) / 2;
            
            comparisons += mergeSort(arr, left, mid);
            comparisons += mergeSort(arr, mid + 1, right);
            
            comparisons += merge(arr, left, mid, right);
        }
        
        return comparisons;
    }
    
    public static long merge(ArrayList<Integer> arr, int left, int mid, int right) {
        int[] temp = new int[right - left + 1];
        int i = left, j = mid + 1, k = 0;
        long comparisons = 0;
        
        while (i <= mid && j <= right) {
            if (arr.get(i) <= arr.get(j)) {
                temp[k++] = arr.get(i++);
            } else {
                temp[k++] = arr.get(j++);
            }
            comparisons++;
        }
        
        while (i <= mid) {
            temp[k++] = arr.get(i++);
        }
        
        while (j <= right) {
            temp[k++] = arr.get(j++);
        }
        
        for (i = left, k = 0; i <= right; i++, k++) {
            arr.set(i, temp[k]);
        }
        
        return comparisons;
    }
}
