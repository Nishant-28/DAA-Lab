#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partitioning function for quicksort
int partition(int arr[], int low, int high, long long int* comparisons) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick sort function
void quickSort(int arr[], int low, int high, long long int* comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);

        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

// Function to read data from a file and return the number of elements
int readDataFromFile(const char* filename, int arr[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        exit(1);
    }

    int count = 0;
    while (!feof(file)) {
        fscanf(file, "%d", &arr[count]);
        count++;
    }

    fclose(file);
    return count;
}

// Function to write data to a file
void writeDataToFile(const char* filename, int arr[], int size) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

int main() {
    int choice;
    long long int comparisons = 0;

    do {
        printf("MAIN MENU (QUICK SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            const char* inputFilename;
            const char* outputFilename;
            
            switch (choice) {
                case 1:
                    inputFilename = "inAsce.dat";
                    outputFilename = "outQuickAsce.dat";
                    break;
                case 2:
                    inputFilename = "inDesc.dat";
                    outputFilename = "outQuickDesc.dat";
                    break;
                case 3:
                    inputFilename = "inRand.dat";
                    outputFilename = "outQuickRand.dat";
                    break;
            }
            
            int arr[500];
            int size = readDataFromFile(inputFilename, arr);
            
            comparisons = 0;
            quickSort(arr, 0, size - 1, &comparisons);
            writeDataToFile(outputFilename, arr, size);
            
            printf("Before Sorting: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\nAfter Sorting: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\nNumber of Comparisons: %lld\n", comparisons);
            
            int mid = size / 2;
            if (comparisons == mid * (mid - 1) / 2 || comparisons == (size * (size - 1)) / 2) {
                printf("Scenario: Best-case\n");
            } else {
                printf("Scenario: Worst-case\n");
            }
            
        } else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (1);

    return 0;
}
