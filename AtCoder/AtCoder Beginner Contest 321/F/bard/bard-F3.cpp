#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
  int Q, K;
  cin >> Q >> K;

  // Create a vector to store the balls in the box.
  vector<int> balls(K + 1, 0);

  // Create a 2D DP table to store the number of ways to pick up some number of balls from the box so that the integers written on them sum to K.
  vector<vector<int>> dp(Q + 1, vector<int>(K + 1, 0));

  // Initialize the DP table.
  dp[0][0] = 1;

  // Iterate over the operations.
  for (int i = 1; i <= Q; i++) {
    // Get the current operation.
    int operation;
    cin >> operation;

    // If the operation is to add a ball, update the DP table accordingly.
    if (operation == 1) {
      int x;
      cin >> x;

      for (int j = 0; j <= K; j++) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
        if (j >= x) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
        }
      }
    }

    // If the operation is to remove a ball, update the DP table accordingly.
    else if (operation == -1) {
      int x;
      cin >> x;

      for (int j = 0; j <= K; j++) {
        if (j >= x) {
          dp[i][j] = (dp[i][j] - dp[i - 1][j - x] + MOD) % MOD;
        }
      }
    }
  }

  // Print the answer for each operation.
  for (int i = 0; i <= Q; i++) {
    cout << dp[i][K] << endl;
  }

  return 0;
}
