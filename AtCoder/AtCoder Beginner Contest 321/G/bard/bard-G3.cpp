#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> r(m), b(m);
  for (int i = 0; i < m; i++) {
    cin >> r[i] >> b[i];
    r[i]--, b[i]--;
  }

  // dp[i][j] is the number of ways to connect the first i cables
  // in such a way that there are j connected components.
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  dp[0][1] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      // Connect the i-th cable to the j-th blue terminal.
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      // Connect the i-th cable to the same blue terminal as the (i - 1)-th cable
      // if r[i] == r[i - 1].
      if (r[i] == r[i - 1]) {
        dp[i][j] += dp[i - 2][j];
      }
      dp[i][j] %= MOD;
    }
  }

  // The expected value of s is the sum of the number of ways to connect
  // the cables in such a way that there are j connected components,
  // divided by the total number of ways to connect the cables.
  int expected_value = 0;
  for (int j = 1; j <= n; j++) {
    expected_value += dp[m][j];
    expected_value %= MOD;
  }

  // Calculate the inverse of the total number of ways to connect the cables.
  int inverse_of_total_ways = 1;
  for (int i = 1; i <= m; i++) {
    inverse_of_total_ways *= i;
    inverse_of_total_ways %= MOD;
  }
  inverse_of_total_ways = modinv(inverse_of_total_ways, MOD);

  // Calculate the expected value, modulo MOD.
  expected_value *= inverse_of_total_ways;
  expected_value %= MOD;

  cout << expected_value << endl;

  return 0;
}

// Calculate the modular inverse of a modulo m.
int modinv(int a, int m) {
  int b = m, u = 1, v = 0;
  while (b) {
    int t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) {
    u += m;
  }
  return u;
}
