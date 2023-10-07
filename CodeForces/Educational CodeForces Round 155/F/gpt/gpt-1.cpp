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
        
        vector<int> h(n);
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<pair<long long, int>> points;  // Stores points as a pair of (points, hero index)
        long long total_damage = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] >= h[(i + 1) % n]) {
                points.push_back({1, i});
            } else {
                long long rounds = (h[i] - a[i] + a[(i + 1) % n] - 1) / a[(i + 1) % n];
                total_damage += rounds * a[(i + 1) % n];
                points.push_back({rounds + 1, i});
            }
        }

        sort(points.begin(), points.end(), greater<pair<long long, int>>());

        vector<long long> max_points(n, 0);
        long long current_points = 0;

        for (int i = 0; i < n; i++) {
            current_points += points[i].first;
            max_points[points[i].second] = max(max_points[points[i].second], current_points);
        }

        for (int i = 0; i < n; i++) {
            cout << max_points[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
