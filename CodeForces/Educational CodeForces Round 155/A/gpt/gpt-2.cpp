#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> athletes(n);

        for (int i = 0; i < n; i++) {
            cin >> athletes[i].first >> athletes[i].second;
        }

        sort(athletes.begin(), athletes.end());

        long long left = 1, right = 2e9, ans = -1;

        while (left <= right) {
            long long mid = (left + right) / 2;
            long long total_lifts = 0;

            for (int i = 0; i < n; i++) {
                if (athletes[i].first >= mid) {
                    total_lifts += athletes[i].second;
                } else {
                    break;
                }
            }

            if (total_lifts >= mid) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
