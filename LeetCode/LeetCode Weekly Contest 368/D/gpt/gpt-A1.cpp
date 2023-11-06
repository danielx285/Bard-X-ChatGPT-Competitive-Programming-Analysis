class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0)); // dp[i][j] stores the minimum changes required for s[i:j] to be a semi-palindrome
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = dp[i + 1][j - 1] + (s[i] != s[j]);
            }
        }

        // Function to calculate the total changes required for k partitions
        function<int(int, int)> dfs = [&](int i, int k) {
            if (k == 1) {
                return dp[i][n - 1];
            }
            int min_changes = INT_MAX;
            for (int j = i; j < n - 1; ++j) {
                min_changes = min(min_changes, dp[i][j] + dfs(j + 1, k - 1));
            }
            return min_changes;
        };

        return dfs(0, k);
    }
};
