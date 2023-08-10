#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr, int& comparisons) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }

        arr[j + 1] = key;
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int choice;
    vector<int> data;
    int comparisons = 0;

    while (true) {
        cout << "MAIN MENU (INSERTION SORT)" << endl;
        cout << "1. Ascending Data" << endl;
        cout << "2. Descending Data" << endl;
        cout << "3. Random Data" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter option: ";
        cin >> choice;

        if (choice == 4) {
            break;
        }

        ifstream inputFile;
        string inputFileName;
        switch (choice) {
            case 1:
                inputFileName = "inAsce.dat";
                break;
            case 2:
                inputFileName = "inDesc.dat";
                break;
            case 3:
                inputFileName = "inRand.dat";
                break;
            default:
                cout << "Invalid choice." << endl;
                continue;
        }

        inputFile.open(inputFileName);
        if (!inputFile) {
            cout << "Error opening file: " << inputFileName << endl;
            continue;
        }

        int num;
        data.clear();
        while (inputFile >> num) {
            data.push_back(num);
        }
        inputFile.close();

        cout << "Before Sorting: ";
        printArray(data);

        comparisons = 0;
        insertionSort(data, comparisons);

        cout << "After Sorting: ";
        printArray(data);

        cout << "Number of Comparisons: " << comparisons << endl;
        
        // Determine and display the scenario
        if (comparisons == 0) {
            cout << "Scenario: Best-case" << endl;
        } else if (comparisons == data.size() * (data.size() - 1) / 2) {
            cout << "Scenario: Worst-case" << endl;
        } else {
            cout << "Scenario: Intermediate-case" << endl;
        }
    }

    return 0;
}
