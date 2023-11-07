#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canFormPalindrome(string s, int k) {
    vector<int> freq(26, 0);

    // Count the frequency of each character in the string
    for (char c : s) {
        freq[c - 'a']++;
    }

    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
        }
    }

    // We can remove (oddCount - 1) characters from the string to make it a palindrome.
    // The -1 is because we can have at most one character with an odd count in a palindrome.

    return k >= oddCount - 1 && k <= s.length() - 1;
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
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
