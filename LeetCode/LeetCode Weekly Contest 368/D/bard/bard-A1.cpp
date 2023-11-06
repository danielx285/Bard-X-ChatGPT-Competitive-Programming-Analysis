class Solution {
public:
    int minimumChanges(string s, int k) {
        // Create a table to store the minimum number of changes required to make each substring a semi-palindrome.
        int dp[s.length() + 1][k + 1];
        for (int i = 0; i <= s.length(); i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = INT_MAX;
            }
        }

        // Initialize the base cases.
        dp[0][0] = 0;
        for (int i = 1; i <= s.length(); i++) {
            dp[i][1] = countChanges(s, 0, i - 1);
        }

        // Fill in the table using dynamic programming.
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 2; j <= k; j++) {
                for (int l = 0; l < i; l++) {
                    dp[i][j] = min(dp[i][j], dp[l][j - 1] + countChanges(s, l, i - 1));
                }
            }
        }

        // Return the minimum number of changes required to make all substrings semi-palindromes.
        return dp[s.length()][k];
    }

private:
    // Counts the number of changes required to make the given substring a semi-palindrome.
    int countChanges(string& s, int i, int j) {
        int count = 0;
        int len = j - i + 1;

        // Find the largest divisor of len that is less than len.
        int d = 1;
        for (int k = 2; k < len; k++) {
            if (len % k == 0) {
                d = k;
            }
        }

        // Check if the substring is already a semi-palindrome.
        bool isSemiPalindrome = true;
        for (int k = 0; k < len / 2; k++) {
            if (s[i + k] != s[i + len - k - 1]) {
                isSemiPalindrome = false;
                break;
            }
        }

        // If the substring is not a semi-palindrome, count the number of changes required to make it one.
        if (!isSemiPalindrome) {
            for (int k = 0; k < len / 2; k++) {
                if (s[i + k] != s[i + len - k - 1]) {
                    count++;
                }
            }
        }

        // If the substring has a divisor, count the number of changes required to make it a semi-palindrome with that divisor.
        if (d > 1) {
            count = min(count, countChanges(s, i, i + d - 1) + countChanges(s, i + d, j));
        }

        return count;
    }
};
