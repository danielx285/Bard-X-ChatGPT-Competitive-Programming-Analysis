#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> segments;
        vector<int> start_counts(m + 2, 0);
        vector<int> end_counts(m + 2, 0);

        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            segments.push_back({l, r});
            start_counts[l]++;
            end_counts[r]++;
        }

        vector<long long> changes(m + 1, 0);
        long long cur_changes = 0;

        for (int i = 1; i <= m; i++) {
            cur_changes += start_counts[i];
            changes[i] = cur_changes;
            cur_changes -= end_counts[i];
        }

        sort(changes.begin(), changes.end());

        long long max_cost = 0;

        for (int i = 1; i <= m; i++) {
            long long cost = changes[i] * (m - i) + (n - changes[i]) * i;
            max_cost = max(max_cost, cost);
        }

        cout << max_cost << endl;
    }

    return 0;
}
