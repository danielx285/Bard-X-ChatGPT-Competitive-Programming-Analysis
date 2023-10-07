#include <iostream>
#include <vector>

using namespace std;

bool can_fill_knapsack(int n, int k, int x) {
  // Create a table to store the maximum value that can be achieved by
  // considering the first i items and using at most j items.
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

  // For an empty knapsack, the maximum value is 0.
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }

  // For a knapsack with only 1 item, the maximum value is the value of the item.
  for (int i = 1; i <= n; i++) {
    dp[i][1] = i;
  }

  // Iterate over the remaining items and the capacity of the knapsack.
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= k; j++) {
      // If the item weight is greater than the knapsack capacity,
      // then the maximum value is the same as the maximum value without
      // the item.
      if (i > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        // The maximum value is the maximum of the following two cases:
        // 1. The maximum value without the item.
        // 2. The maximum value with the item, plus the value of the item.
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - i] + i);
      }
    }
  }

  // Return true if the maximum value is equal to the target value,
  // and false otherwise.
  return dp[n][k] == x;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k, x;
    cin >> n >> k >> x;

    if (can_fill_knapsack(n, k, x)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
