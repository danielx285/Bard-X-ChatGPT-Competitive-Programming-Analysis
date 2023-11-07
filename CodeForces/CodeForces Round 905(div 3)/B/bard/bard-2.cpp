#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool canRearrangeToFormPalindrome(string s, int k) {
  // Create a count array to count the frequency of each character in the string.
  vector<int> count(26, 0);
  for (char c : s) {
    count[c - 'a']++;
  }

  // Count the number of odd occurrences of characters.
  int oddCount = 0;
  for (int i = 0; i < 26; i++) {
    if (count[i] % 2 == 1) {
      oddCount++;
    }
  }

  // If the number of odd occurrences of characters is greater than k, then it is
  // not possible to rearrange the string to form a palindrome.
  return oddCount <= k;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if (canRearrangeToFormPalindrome(s, k)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
