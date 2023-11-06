#include <vector>
#include <string>
#include <climits>

class Solution {
public:
    int minimumChanges(std::string s, int k) {
        int n = s.length();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, INT_MAX));

        // Calculate the number of changes needed to make substrings semi-palindromes
        std::vector<int> changes(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            changes[i] = changes[i - 1] + isSemiPalindrome(s.substr(i - 1, 1));
        }

        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int l = j - 1; l <= i - 1; l++) {
                    if (dp[l][j - 1] != INT_MAX) {
                        dp[i][j] = std::min(dp[i][j], dp[l][j - 1] + changes[i] - changes[l]);
                    }
                }
            }
        }

        return dp[n][k];
    }

    int isSemiPalindrome(std::string s) {
        int n = s.length();
        for (int d = 1; d < n; d++) {
            if (n % d == 0) {
                bool isPalindrome = true;
                for (int i = 0; i < d; i++) {
                    if (s[i] != s[0]) {
                        isPalindrome = false;
                        break;
                    }
                }
                if (isPalindrome) {
                    return 0;
                }
            }
        }
        return 1;
    }
};

int main() {
    Solution solution;
    std::string s1 = "abcac";
    int k1 = 2;
    std::cout << solution.minimumChanges(s1, k1) << std::endl;  // Output: 1

    std::string s2 = "abcdef";
    int k2 = 2;
    std::cout << solution.minimumChanges(s2, k2) << std::endl;  // Output: 2

    std::string s3 = "aabbaa";
    int k3 = 3;
    std::cout << solution.minimumChanges(s3, k3) << std::endl;  // Output: 0

    return 0;
}
