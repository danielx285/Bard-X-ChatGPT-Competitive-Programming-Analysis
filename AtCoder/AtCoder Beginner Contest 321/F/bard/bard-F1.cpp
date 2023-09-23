#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
  int Q, K;
  cin >> Q >> K;

  vector<int> balls;
  vector<int> dp(K + 1, 0);
  dp[0] = 1;

  for (int i = 0; i < Q; i++) {
    char type;
    int x;
    cin >> type >> x;

    if (type == '+') {
      balls.push_back(x);
      for (int j = x; j <= K; j++) {
        dp[j] = (dp[j] + dp[j - x]) % MOD;
      }
    } else if (type == '-') {
      for (int j = x; j <= K; j++) {
        dp[j] = (dp[j] - dp[j - x] + MOD) % MOD;
      }
      balls.erase(remove(balls.begin(), balls.end(), x), balls.end());
    }

    cout << dp[K] << endl;
  }

  cout << "This input contains " << Q << " operations." << endl;
  cout << "After the last operation, the box contains the balls (";
  for (int i = 0; i < balls.size(); i++) {
    cout << balls[i] << ",";
  }
  cout << ")" << endl;
  cout << "There are " << dp[K] << " ways to pick up balls for a sum of " << K << ":";
  return 0;
}
