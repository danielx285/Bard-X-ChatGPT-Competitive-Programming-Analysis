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

        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        // Calculate the sum of a and b
        long long sum_a = 0, sum_b = 0;

        for (int i = 0; i < n; i++) {
            sum_a += a[i];
            sum_b += b[i];
        }

        // Sort both a and b arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // The minimum cost is the sum of a and b, but we need to subtract the maximum value from either a or b
        long long min_cost = sum_a + sum_b - max(a[n - 1], b[n - 1]);

        cout << min_cost << endl;
    }

    return 0;
}
