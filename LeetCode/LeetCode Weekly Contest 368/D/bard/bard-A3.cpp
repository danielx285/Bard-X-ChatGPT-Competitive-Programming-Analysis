class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        int dp[n + 1][k + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = INT_MAX;
                } else if (i == j) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = INT_MAX;
                    for (int d = 1; d < i; d++) {
                        if (i % d == 0) {
                            string substring = s.substr(0, d);
                            int changes = 0;
                            for (int j = 0; j < d / 2; j++) {
                                if (substring[j] != substring[d - j - 1]) {
                                    changes++;
                                }
                            }
                            dp[i][j] = min(dp[i][j], changes + dp[i - d][j - 1]);
                        }
                    }
                }
            }
        }
        return dp[n][k];
    }
};
