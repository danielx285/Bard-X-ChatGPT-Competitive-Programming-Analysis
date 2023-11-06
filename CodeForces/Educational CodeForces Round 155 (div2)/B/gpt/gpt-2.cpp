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
        
        vector<long long> a(n), b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<long long> row_costs(n), col_costs(n);

        // Calculate cumulative sums for arrays a and b
        vector<long long> cumulative_a(n), cumulative_b(n);
        cumulative_a[0] = a[0];
        cumulative_b[0] = b[0];

        for (int i = 1; i < n; i++) {
            cumulative_a[i] = cumulative_a[i - 1] + a[i];
            cumulative_b[i] = cumulative_b[i - 1] + b[i];
        }

        // Calculate minimum cost for each row and column
        for (int i = 0; i < n; i++) {
            row_costs[i] = cumulative_a[i] + b[i] * (n - i - 1) + (cumulative_b[n - 1] - cumulative_b[i]);
            col_costs[i] = cumulative_b[i] + a[i] * (n - i - 1) + (cumulative_a[n - 1] - cumulative_a[i]);
        }

        // Find the minimum cost for rows and columns
        long long min_row_cost = *min_element(row_costs.begin(), row_costs.end());
        long long min_col_cost = *min_element(col_costs.begin(), col_costs.end());

        // Calculate the total minimum cost
        long long total_cost = min(min_row_cost, min_col_cost);

        cout << total_cost << endl;
    }

    return 0;
}
