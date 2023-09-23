#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

vector<int> dp;

int main() {
  int Q, K;
  cin >> Q >> K;

  dp.resize(K + 1, 0);
  dp[0] = 1;

  for (int i = 0; i < Q; i++) {
    int x;
    cin >> x;

    if (x > 0) {
      // Add a ball with weight x.
      for (int j = K; j >= x; j--) {
        dp[j] = (dp[j] + dp[j - x]) % MOD;
      }
    } else {
      // Remove a ball with weight x.
      for (int j = x; j <= K; j++) {
        dp[j] = (dp[j] - dp[j - x] + MOD) % MOD;
      }
    }

    cout << dp[K] << endl;
  }

  return 0;
}
