#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        
        // Calculate the number of changes required to make every substring a semi-palindrome.
        vector<vector<int>> changes(n, vector<int>(n, 0));
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                changes[i][j] = changes[i + 1][j - 1] + (s[i] != s[j]);
            }
        }
        
        // Initialize the dp array for dynamic programming.
        vector<vector<int>> dp(n, vector<int>(k + 1, n));
        
        // Fill the dp array.
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (j == 1) {
                    dp[i][j] = changes[0][i];
                } else {
                    for (int x = 1; x <= i; ++x) {
                        dp[i][j] = min(dp[i][j], dp[x - 1][j - 1] + changes[x][i]);
                    }
                }
            }
        }
        
        return dp[n - 1][k];
    }
};
