#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> spots(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> spots[i][0] >> spots[i][1];
    }

    int num = 0;
    for (int i = 0; i < n; ++i) {
        num = max(num, spots[i][0] + 1);
        spots[i][0] = max(1, spots[i][0] - spots[i][1] + 1);
    }

    vector<int> times(m);
    for (int i = 0; i < m; ++i) {
        cin >> times[i];
        times[i] += k;
    }

    vector<int> temp(num * 2);
    for (const vector<int>& spot : spots) {
        temp[spot[0]]++;
        temp[spot[1] + 1]--;
    }

    for (int i = 1; i <= num; ++i) {
        temp[i] += temp[i - 1];
    }

    for (int time : times) {
        cout << temp[time] << endl;
    }

    return 0;
}