#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    int n = s.size();

    // dp[i][j] stores the minimum number of operations required to make the
    // substring s[i...j] alternating, and the number of different shortest
    // sequences of operations modulo MOD.
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {0, 0}));

    // Base cases.
    for (int i = n - 1; i >= 0; i--) {
      dp[i][i].first = (s[i] - '0') % 2;
      dp[i][i].second = 1;
    }

    // Fill in the rest of the table.
    for (int i = n - 2; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        // If the current substring is already alternating, we don't need to
        // perform any operations.
        if ((s[i] - '0') % 2 != (s[j] - '0') % 2) {
          dp[i][j] = {0, 1};
        } else {
          // Otherwise, we can either delete the i-th character or the j-th
          // character. We need to choose the option that requires the fewest
          // operations.
          dp[i][j].first = min(dp[i + 1][j].first + 1, dp[i][j - 1].first + 1);
          dp[i][j].second = (dp[i + 1][j].second + dp[i][j - 1].second) % MOD;
        }
      }
    }

    // Print the answer.
    cout << dp[0][n - 1].first << " "
         << dp[0][n - 1].second << endl;
  }

  return 0;
}
