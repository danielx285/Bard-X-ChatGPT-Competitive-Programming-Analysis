#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long n, x, k;
    cin >> n >> x >> k;

    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

    // Base case: dp[v][0] = 1 for all vertices v.
    for (int v = 1; v <= n; v++) {
      dp[v][0] = 1;
    }

    // Recurrence: dp[v][i] = dp[v/2][i-1] for i > 0.
    for (int i = 1; i <= k; i++) {
      for (int v = 1; v <= n; v++) {
        dp[v][i] = dp[v / 2][i - 1];
      }
    }

    // Count the number of vertices whose distance from vertex x is k.
    long long count = 0;
    for (int v = 1; v <= n; v++) {
      if (dp[v][k] == 1) {
        count++;
      }
    }

    cout << count << endl;
  }

  return 0;
}
