#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    // dp[i] stores the maximum score that can be obtained when there are i cards left in the deck.
    vector<int> dp(n + 1, 0);

    // Initialize the base case.
    dp[0] = 0;

    // Iterate over the number of cards left in the deck.
    for (int i = 1; i <= n; i++) {
      // If the current card is odd, then we can either take it or leave it.
      if (i % 2 == 1) {
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i - 1]);
      }

      // If the current card is even, then we can only leave it.
      else {
        dp[i] = dp[i - 1];
      }
    }

    // Print the maximum score.
    cout << dp[n] << endl;
  }

  return 0;
}
