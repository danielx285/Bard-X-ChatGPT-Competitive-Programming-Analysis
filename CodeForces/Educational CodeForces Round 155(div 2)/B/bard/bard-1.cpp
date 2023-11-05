#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
      dp[i][0] = dp[i - 1][0] + a[i - 1];
      dp[0][i] = dp[0][i - 1] + b[i - 1];
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = min(dp[i - 1][j] + a[i - 1], dp[i][j - 1] + b[j - 1]);
      }
    }

    cout << dp[n][n] << endl;
  }

  return 0;
}
