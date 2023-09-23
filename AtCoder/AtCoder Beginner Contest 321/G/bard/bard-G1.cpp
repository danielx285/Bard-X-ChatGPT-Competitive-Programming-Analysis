#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> r(m), b(m);
  for (int i = 0; i < m; i++) {
    cin >> r[i] >> b[i];
  }

  // dp[i][j] is the number of ways to connect the first i cables such that
  // there are j connected components.
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  dp[0][n] = 1;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      // If we connect the ith cable to the same red and blue terminals as
      // the (i - 1)th cable, then there will be j connected components.
      dp[i][j] = dp[i - 1][j];

      // If we connect the ith cable to different red and blue terminals than
      // the (i - 1)th cable, then there will be j - 1 connected components.
      dp[i][j - 1] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
    }
  }

  // The expected value of the number of connected components is the sum of
  // the number of ways to connect the cables such that there are j connected
  // components, divided by the total number of ways to connect the cables.
  int expected_value = 0;
  for (int j = 1; j <= n; j++) {
    expected_value = (expected_value + dp[m][j]) % MOD;
  }

  cout << expected_value << endl;

  return 0;
}
