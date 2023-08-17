
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Merge Sort
long long merge(long long arr[], long long temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long comparisons = 0;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
        comparisons++;
    }

    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return comparisons;
}

long long mergeSort(long long arr[], long long temp[], int left, int right) {
    long long comparisons = 0;
    if (right > left) {
        int mid = (left + right) / 2;
        comparisons += mergeSort(arr, temp, left, mid);
        comparisons += mergeSort(arr, temp, mid + 1, right);
        comparisons += merge(arr, temp, left, mid + 1, right);
    }
    return comparisons;
}

int main() {
    FILE *inputFile, *outputFile;
    int choice, i, n;
    clock_t start, end;
    double cpu_time_used;
    
    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. Exit\n");
    
    printf("Enter option: ");
    scanf("%d", &choice);
    
    char *inputFilename, *outputFilename;
    
    switch (choice) {
        case 1:
            inputFilename = "inAsce.dat";
            outputFilename = "outMergeAsce.dat";
            break;
        case 2:
            inputFilename = "inDesc.dat";
            outputFilename = "outMergeDesc.dat";
            break;
        case 3:
            inputFilename = "inRand.dat";
            outputFilename = "outMergeRand.dat";
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid option!\n");
            exit(1);
    }
    
    inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(1);
    }
    
    fscanf(inputFile, "%d", &n);
    long long arr[n], temp[n];
    for (i = 0; i < n; i++) {
        fscanf(inputFile, "%lld", &arr[i]);
    }
    fclose(inputFile);

    start = clock();
    long long comparisons = mergeSort(arr, temp, 0, n - 1);
    end = clock();

    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(1);
    }
    
    fprintf(outputFile, "After Sorting:\n");
    for (i = 0; i < n; i++) {
        fprintf(outputFile, "%lld ", arr[i]);
    }
    fclose(outputFile);

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1e9; // Convert to nanoseconds
    
    printf("Number of Comparisons: %lld\n", comparisons);
    printf("Execution Time: %lf nanoseconds\n", cpu_time_used);

    return 0;
}
