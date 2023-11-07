#include <iostream>
#include <vector>

using namespace std;

bool isPossibleToPalindrome(string s, int k) {
    int n = s.size();
    vector<int> count(26, 0); // Array to count occurrences of each character

    // Count the occurrences of each character in the string
    for (char c : s) {
        count[c - 'a']++;
    }

    int oddCount = 0; // Count of characters with odd occurrences
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0) {
            oddCount++;
        }
    }

    // If k is greater than or equal to the number of odd occurrences, it's possible to make a palindrome
    if (k >= oddCount && (k - oddCount) % 2 == 0) {
        return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        if (isPossibleToPalindrome(s, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
