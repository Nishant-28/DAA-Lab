#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Function to partition the array and return the partition index
int partition(vector<int>& arr, int low, int high, int& comparisons) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform Quick Sort
void quickSort(vector<int>& arr, int low, int high, int& comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

int main() {
    int option;
    cout << "MAIN MENU (QUICK SORT)" << endl;
    cout << "1. Ascending Data" << endl;
    cout << "2. Descending Data" << endl;
    cout << "3. Random Data" << endl;
    cout << "4. EXIT" << endl;
    cout << "Enter option: ";
    cin >> option;

    const char* inputFilename;
    const char* outputFilename;
    
    switch (option) {
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
        case 4:
            return 0;
        default:
            cout << "Invalid option. Exiting." << endl;
            return 1;
    }

    ifstream inputFile(inputFilename);
    if (!inputFile) {
        cout << "Error opening input file." << endl;
        return 1;
    }

    vector<int> data;
    int num;
    while (inputFile >> num) {
        data.push_back(num);
    }
    inputFile.close();

    int comparisons = 0;
    quickSort(data, 0, data.size() - 1, comparisons);

    ofstream outputFile(outputFilename);
    for (int num : data) {
        outputFile << num << " ";
    }
    outputFile.close();

    cout << "Before Sorting: Content of the input file" << endl;
    ifstream inputDisplay(inputFilename);
    string line;
    while (getline(inputDisplay, line)) {
        cout << line << endl;
    }
    inputDisplay.close();

    cout << "After Sorting: Content of the output file" << endl;
    ifstream outputDisplay(outputFilename);
    while (getline(outputDisplay, line)) {
        cout << line << endl;
    }
    outputDisplay.close();

    cout << "Number of Comparisons: " << comparisons << endl;

    if (comparisons == 0)
        cout << "Scenario: Best-case partitioning" << endl;
    else if (comparisons == (data.size() * (data.size() - 1)) / 2)
        cout << "Scenario: Worst-case partitioning" << endl;
    else
        cout << "Scenario: Neither best-case nor worst-case partitioning" << endl;

    return 0;
}
