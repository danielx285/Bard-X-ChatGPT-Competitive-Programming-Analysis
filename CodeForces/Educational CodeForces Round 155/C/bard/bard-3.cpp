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

    // dp[i][j] stores the minimum number of operations required to make s[i:] alternating,
    // starting with s[i] = j.
    vector<vector<int>> dp(n, vector<int>(2, -1));

    // Base cases.
    dp[n - 1][0] = 0;
    dp[n - 1][1] = 0;

    // Recursive cases.
    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j < 2; j++) {
        // If the current character is the same as the previous character, we need to delete one of them.
        if (s[i] == s[i + 1]) {
          dp[i][j] = 1 + dp[i + 1][(j + 1) % 2];
        } else {
          // If the current character is different from the previous character, we can either keep it or delete it.
          dp[i][j] = min(dp[i + 1][j], 1 + dp[i + 1][(j + 1) % 2]);
        }
      }
    }

    // Calculate the number of different shortest sequences of operations.
    int count = 0;
    for (int i = 0; i < 2; i++) {
      if (dp[0][i] == dp[0][0]) {
        count = (count + 1) % MOD;
      }
    }

    // Print the answer.
    cout << dp[0][0] << " " << count << endl;
  }

  return 0;
}
