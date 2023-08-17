#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Function to perform Merge Sort
long long merge(vector<int> &arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];

    long long comparisons = 0;
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparisons++;
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while (i < n1)
        arr[k++] = leftArr[i++];
    while (j < n2)
        arr[k++] = rightArr[j++];

    return comparisons;
}

long long mergeSort(vector<int> &arr, int left, int right) {
    long long comparisons = 0;

    if (left < right) {
        int middle = left + (right - left) / 2;
        comparisons += mergeSort(arr, left, middle);
        comparisons += mergeSort(arr, middle + 1, right);
        comparisons += merge(arr, left, middle, right);
    }

    return comparisons;
}

void printArray(const vector<int> &arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    int option;
    cout << "MAIN MENU (MERGE SORT)\n";
    cout << "1. Ascending Data\n";
    cout << "2. Descending Data\n";
    cout << "3. Random Data\n";
    cout << "4. Exit\n";

    cout << "Enter option: ";
    cin >> option;

    string inputFileName, outputFileName;
    switch (option) {
        case 1:
            inputFileName = "inAsce.dat";
            outputFileName = "outMergeAsce.dat";
            break;
        case 2:
            inputFileName = "inDesc.dat";
            outputFileName = "outMergeDesc.dat";
            break;
        case 3:
            inputFileName = "inRand.dat";
            outputFileName = "outMergeRand.dat";
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid option. Exiting...\n";
            return 1;
    }

    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cout << "Error opening input file.\n";
        return 1;
    }

    int num;
    vector<int> arr;
    while (inputFile >> num)
        arr.push_back(num);
    inputFile.close();

    cout << "Before Sorting: ";
    printArray(arr);

    auto start = high_resolution_clock::now();
    long long comparisons = mergeSort(arr, 0, arr.size() - 1);
    auto stop = high_resolution_clock::now();

    cout << "After Sorting: ";
    printArray(arr);

    ofstream outputFile(outputFileName);
    for (int num : arr)
        outputFile << num << " ";
    outputFile.close();

    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Number of Comparisons: " << comparisons << endl;
    cout << "Execution Time: " << duration.count() << " nanoseconds\n";

    return 0;
}
