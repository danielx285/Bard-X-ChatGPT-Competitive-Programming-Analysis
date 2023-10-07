#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

// Returns the minimum number of operations required to make the given string alternating.
int min_operations(string s) {
  int n = s.size();
  vector<int> dp(n, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    // If the current character and the previous character are the same, then we need to delete one of them.
    if (s[i] == s[i - 1]) {
      dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    // Otherwise, we can simply keep both characters.
    else {
      dp[i] = min(dp[i], dp[i - 1]);
    }
  }
  return dp[n - 1];
}

// Returns the number of different shortest sequences of operations that make the given string alternating.
int count_sequences(string s) {
  int n = s.size();
  vector<vector<int>> dp(n, vector<int>(2, 0));
  dp[0][0] = 1;
  for (int i = 1; i < n; i++) {
    // If the current character and the previous character are the same, then we can either delete the current character or keep both characters.
    if (s[i] == s[i - 1]) {
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
    }
    // Otherwise, we can only keep both characters.
    else {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][1];
    }
  }
  return dp[n - 1][0];
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int min_ops = min_operations(s);
    int count_seqs = count_sequences(s);
    cout << min_ops << " " << count_seqs % MOD << endl;
  }
  return 0;
}
