#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    vector<int> cities = {1, 2, 3};
    int min_path = 9999;

    do {
        int current_cost = 0;
        int k = 0;

        for (int i = 0; i < cities.size(); i++) {
            current_cost += graph[k][cities[i]];
            k = cities[i];
        }

        current_cost += graph[k][0]; // return to start

        min_path = min(min_path, current_cost);

    } while (next_permutation(cities.begin(), cities.end()));

    cout << "Minimum travelling cost: " << min_path;

    return 0;
}