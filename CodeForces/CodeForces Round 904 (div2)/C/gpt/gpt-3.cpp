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
        vector<long long> diff(m + 1, 0);

        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            segments.push_back({l, r});
            diff[l]++;
            diff[r + 1]--;
        }

        for (int i = 1; i <= m; i++) {
            diff[i] += diff[i - 1];
        }

        vector<long long> a(m + 1, 0);

        for (int i = 0; i < n; i++) {
            int l = segments[i].first;
            int r = segments[i].second;
            a[l] += diff[i];
            a[r + 1] -= diff[i];
        }

        for (int i = 1; i <= m; i++) {
            a[i] += a[i - 1];
        }

        long long max_a = *max_element(a.begin(), a.end());
        long long min_a = *min_element(a.begin(), a.end());

        long long cost = max_a - min_a;
        cout << cost << endl;
    }

    return 0;
}
