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
Maximum profit: 34.437500 */

import java.util.Scanner;

class ITEM {
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
}


public class q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of items: ");
        int n = sc.nextInt();
        ITEM[] item = new ITEM[n];
        for (int i = 0; i < n; i++) {
            item[i] = new ITEM();
            System.out.println("Enter the profit and weight of item no " + (i + 1) + ": ");
            item[i].item_profit = sc.nextFloat();
            item[i].item_weight = sc.nextFloat();
            item[i].profit_weight_ratio = item[i].item_profit / item[i].item_weight;
            item[i].item_id = i + 1;
        }
        System.out.println("Enter the capacity of knapsack: ");
        float capacity = sc.nextFloat();
        float max_profit = 0;
        float weight = 0;
        float[] amount = new float[n];
        for (int i = 0; i < n; i++) {
            amount[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            if (weight + item[i].item_weight <= capacity) {
                weight += item[i].item_weight;
                amount[item[i].item_id - 1] = 1;
                max_profit += item[i].item_profit;
            } else {
                amount[item[i].item_id - 1] = (capacity - weight) / item[i].item_weight;
                max_profit += amount[item[i].item_id - 1] * item[i].item_profit;
                break;
            }
        }
        System.out.println("Item No\tProfit\tWeight\tAmount to be taken");
        for (int i = 0; i < n; i++) {
            System.out.println(item[i].item_id + "\t" + item[i].item_profit + "\t" + item[i].item_weight + "\t" + amount[i]);
        }
        System.out.println("Maximum profit: " + max_profit);
    }
}   

