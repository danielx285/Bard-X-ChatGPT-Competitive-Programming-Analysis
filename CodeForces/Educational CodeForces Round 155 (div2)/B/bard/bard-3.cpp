#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

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

    vector<int> prefix_sum_a(n + 1, 0);
    vector<int> prefix_sum_b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      prefix_sum_a[i] = prefix_sum_a[i - 1] + a[i - 1];
      prefix_sum_b[i] = prefix_sum_b[i - 1] + b[i - 1];
    }

    // dp[i][j] = the minimum cost of placing chips on the first i rows and j columns
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        // Place a chip in the current cell.
        dp[i][j] = min(dp[i][j], prefix_sum_a[i] + prefix_sum_b[j]);

        // Do not place a chip in the current cell.
        dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1]));
      }
    }

    cout << dp[n][n] << endl;
  }

  return 0;
}
