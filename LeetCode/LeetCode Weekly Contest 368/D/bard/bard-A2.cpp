class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = 0;

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                if (isSemiPalindrome(s.substr(0, j))) {
                    dp[i][j] = dp[i - 1][0];
                } else {
                    dp[i][j] = min(dp[i][j], dp[i - 1][0] + 1);
                    for (int d = 1; d < j; d++) {
                        if (j % d == 0 && isSemiPalindrome(s.substr(0, j), d)) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][j - d] + 1);
                        }
                    }
                }
            }
        }

        return dp[k][n];
    }

private:
    bool isSemiPalindrome(string s) {
        int n = s.size();
        if (n == 1) {
            return true;
        }

        int d = 1;
        while (d < n && n % d != 0) {
            d++;
        }

        if (d == n) {
            return true;
        }

        for (int i = 0; i < n / d; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }

        return true;
    }

    bool isSemiPalindrome(string s, int d) {
        int n = s.size();
        if (n % d != 0) {
            return false;
        }

        for (int i = 0; i < n / d; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }

        return true;
    }
};
