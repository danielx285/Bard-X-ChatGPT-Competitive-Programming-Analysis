#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int>& weights, int n, int k, int x) {
  // Create a table to store the maximum value that can be obtained by
  // choosing k elements from the first i elements, such that the sum of
  // the chosen elements is less than or equal to x.
  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

  // Initialize the first row of the table to 0, since there is no way
  // to choose k elements from the first 0 elements.
  for (int i = 0; i <= x; i++) {
    dp[0][i] = 0;
  }

  // Iterate over the elements of the weights array, and update the table
  // accordingly.
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      // If the weight of the current element is greater than the current
      // capacity, then we cannot choose this element.
      if (weights[i - 1] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        // We can either choose the current element, or not choose it.
        // If we choose the current element, then the maximum value that can
        // be obtained is the sum of the current element and the maximum
        // value that can be obtained by choosing k - 1 elements from the
        // first i - 1 elements.
        // If we do not choose the current element, then the maximum value
        // that can be obtained is the same as the maximum value that can
        // be obtained by choosing k elements from the first i - 1 elements.
        dp[i][j] = max(dp[i - 1][j], weights[i - 1] + dp[i - 1][j - weights[i - 1]]);
      }
    }
  }

  // If the maximum value that can be obtained by choosing k elements from
  // the first n elements is equal to x, then it is possible to choose k
  // distinct integers between 1 and n, such that their sum is equal to x.
  // Otherwise, it is not possible.
  return dp[n][x] == x;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
      cin >> weights[i];
    }

    if (isPossible(weights, n, k, x)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
