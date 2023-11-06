#include <iostream>
#include <vector>

using namespace std;

bool knapsack(int n, int k, int x) {
  vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false));

  // Base case: If we have no items or no capacity, then we can't choose any items.
  dp[0][0] = true;

  // Iterate over the items.
  for (int i = 1; i <= n; i++) {
    // Iterate over the capacity.
    for (int j = 0; j <= x; j++) {
      // If the current item's weight is less than or equal to the remaining capacity,
      // then we can either choose the current item or not choose it.
      if (i <= j) {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - i];
      } else {
        // If the current item's weight is greater than the remaining capacity,
        // then we can't choose it.
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // Return whether we can choose k items with a total weight of x.
  return dp[n][x] && k <= n;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k, x;
    cin >> n >> k >> x;

    if (knapsack(n, k, x)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
