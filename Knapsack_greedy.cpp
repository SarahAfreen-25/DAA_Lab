#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight, profit;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, compare);

    double totalProfit = 0.0;

    for(int i = 0; i < n; i++) {
        if(W >= arr[i].weight) {
            W -= arr[i].weight;
            totalProfit += arr[i].profit;
        }
        else {
            totalProfit += arr[i].profit * ((double)W / arr[i].weight);
            break;
        }
    }
    return totalProfit;
}

int main() {
    int n = 3;
    int W = 50;

    Item arr[n] = {{10,60}, {20,100}, {30,120}};

    cout << "Maximum Profit = " << fractionalKnapsack(W, arr, n);

    return 0;
}