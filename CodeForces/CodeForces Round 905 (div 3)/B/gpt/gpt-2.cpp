#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool canFormPalindrome(string s, int k) {
    vector<int> freq(26, 0); // Frequency of each character
    int oddCount = 0; // Count of characters with odd frequency

    // Calculate character frequencies
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Count characters with odd frequency
    for (int f : freq) {
        if (f % 2 != 0) {
            oddCount++;
        }
    }

    // If k is less than or equal to the number of characters with odd frequency
    // or if k is greater than or equal to the total number of characters,
    // it's possible to form a palindrome
    return (k >= oddCount && k <= s.length());
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        if (canFormPalindrome(s, k)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
