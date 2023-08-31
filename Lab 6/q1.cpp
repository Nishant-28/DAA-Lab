/*Aim of the program: Write a program to find the maximum profit nearest to but not
exceeding the given knapsack capacity using the Fractional Knapsack algorithm.
Notes# Declare a structure ITEM having data members item_id, item_profit, item_weight and
profit_weight_ratio. Apply heap sort technique to sort the items in non-increasing order,
according to their profit /weight.
Input:

Enter the number of items: 3
Enter the profit and weight of item no 1: 27 16
Enter the profit and weight of item no 2: 14 12
Enter the profit and weight of item no 3: 26 13
Enter the capacity of knapsack:18

Output:

Item No Profit Weight Amount to be taken
3 26.000000 13.000000 1.000000
1 27.000000 16.000000 0.312500
2 14.000000 12.000000 0.000000
Maximum profit: 34.437500*/

#include <iostream>
#include <iomanip>
using namespace std;

struct item
{
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
};

void heapify(item arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1; //left child
    int r = 2 * i + 2; //right child

    if (l < n && arr[l].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = l;

    if (r < n && arr[r].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(item arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void knapsack(item arr[], int n, float capacity)
{
    float profit = 0;
    float weight = 0;
    float amount = 0;
    for (int i = 0; i < n; i++)
    {
        if (weight + arr[i].item_weight <= capacity)
        {
            weight += arr[i].item_weight;
            profit += arr[i].item_profit;
            amount = 1;
        }
        else
        {
            amount = (capacity - weight) / arr[i].item_weight;
            weight += amount * arr[i].item_weight;
            profit += amount * arr[i].item_profit;
        }
        cout << arr[i].item_id << "\t" << arr[i].item_profit << "\t" << arr[i].item_weight << "\t" << amount << endl;
    }
    cout << "Maximum profit: " << profit << endl;
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    item arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the profit and weight of item no " << i + 1 << ": ";
        cin >> arr[i].item_profit >> arr[i].item_weight;
        arr[i].item_id = i + 1;
        arr[i].profit_weight_ratio = arr[i].item_profit / arr[i].item_weight;
    }
    cout << "Enter the capacity of knapsack:";
    float capacity;
    cin >> capacity;
    heapSort(arr, n);
    cout << "Item No\tProfit\tWeight\tAmount to be taken" << endl;
    knapsack(arr, n, capacity);
    return 0;
}

