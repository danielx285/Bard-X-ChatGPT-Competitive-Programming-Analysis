#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> segments(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
      cin >> segments[i][0] >> segments[i][1];
    }

    // Create a prefix sum array to store the sum of the segments up to each index.
    vector<int> prefixSum(m + 1, 0);
    for (int i = 0; i < n; i++) {
      prefixSum[segments[i][1]]++;
    }

    // Create a dp array to store the maximum cost of selecting a subset of segments up to each index.
    vector<int> dp(m + 1, 0);
    for (int i = 1; i <= m; i++) {
      // If we select the current segment, then the cost is the maximum of the current prefix sum and the cost of selecting a subset of segments up to the previous index.
      // If we do not select the current segment, then the cost is the same as the cost of selecting a subset of segments up to the previous index.
      dp[i] = max(prefixSum[i], dp[i - 1]);
    }

    // Find the maximum cost among all subsets of segments.
    int maxCost = 0;
    for (int i = 1; i <= m; i++) {
      maxCost = max(maxCost, dp[i]);
    }

    // Print the maximum cost.
    cout << maxCost << endl;
  }

  return 0;
}
