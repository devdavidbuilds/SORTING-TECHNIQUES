#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Item {
    int id;
    int weight;
    int profit;
    float ratio;
};

struct Node {
    int level;
    int profit;
    int weight;
    float bound;
    vector<int> selectedItems; 
};

// Comparator for sorting
bool compareItems(Item a, Item b) {
    return a.ratio > b.ratio;
}

float calculateBound(Node u, int n, int m, const vector<Item>& items) {
    if (u.weight >= m) return 0;

    float profit_bound = (float)u.profit;
    int j = u.level + 1;
    int totweight = u.weight;

    while (j < n && totweight + items[j].weight <= m) {
        totweight += items[j].weight;
        profit_bound += items[j].profit;
        j++;
    }

    if (j < n)
        profit_bound += (m - totweight) * items[j].ratio;

    return profit_bound;
}

int main() {
    int n, m;
    cout << "Enter number of items: ";
    if (!(cin >> n)) return 0;
    cout << "Enter knapsack capacity: ";
    cin >> m;

    vector<Item> items(n);
    cout << "Enter weights and profits for each item:\n";
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1; 
        cin >> items[i].weight >> items[i].profit;
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    // Sort items by profit/weight ratio
    sort(items.begin(), items.end(), compareItems);

    queue<Node> q;
    Node u, v;

    // Initialize root node - compatible with C++98
    v.level = -1;
    v.profit = 0;
    v.weight = 0;
    v.selectedItems.clear(); 
    v.bound = calculateBound(v, n, m, items);

    int maxProfit = 0;
    vector<int> bestItems; 
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();

        if (v.level == n - 1) continue;

        u.level = v.level + 1;

        // --- Branch 1: Include items[u.level] ---
        u.weight = v.weight + items[u.level].weight;
        u.profit = v.profit + items[u.level].profit;
        u.selectedItems = v.selectedItems;
        u.selectedItems.push_back(items[u.level].id);

        if (u.weight <= m && u.profit > maxProfit) {
            maxProfit = u.profit;
            bestItems = u.selectedItems;
        }

        u.bound = calculateBound(u, n, m, items);
        if (u.bound > (float)maxProfit) {
            q.push(u);
        }

        // --- Branch 2: Exclude items[u.level] ---
        u.weight = v.weight;
        u.profit = v.profit;
        u.selectedItems = v.selectedItems; // Use the path without the new item
        u.bound = calculateBound(u, n, m, items);

        if (u.bound > (float)maxProfit) {
            q.push(u);
        }
    }

    cout << "\nMaximum profit = " << maxProfit << endl;
    cout << "Selected Item IDs: ";
    for (size_t i = 0; i < bestItems.size(); i++) {
        cout << bestItems[i] << (i == bestItems.size() - 1 ? "" : ", ");
    }
    cout << endl;

    return 0;
}

