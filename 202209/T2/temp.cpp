#include <bits/stdc++.h>
using namespace std;

void printSet(const set<int>& subset) {
    for (auto it = subset.begin(); it != subset.end(); ++it) {
        if (it != subset.begin()) cout << " ";
        cout << *it;
    }
    cout << endl;
}

void generateSubsets(const vector<int>& arr, int k) {
    set<set<int>> allSubsets;
    int n = arr.size();
    for (int i = 0; i < (1 << n); ++i) {
        set<int> subset;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subset.insert(arr[j]);
            }
        }
        if (subset.size() == k) {
            allSubsets.insert(subset);
        }
    }

    for (const auto& subset : allSubsets) {
        printSet(subset);
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    for (int k = 1; k <= arr.size(); ++k) {
        generateSubsets(arr, k);
    }
    return 0;
}