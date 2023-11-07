#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isPalindrome(string s) {
  int i = 0;
  int j = s.length() - 1;
  while (i < j) {
    if (s[i] != s[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

bool canRearrangeToFormPalindrome(string s, int k) {
  // Count the frequency of each character in the string.
  unordered_map<char, int> charCount;
  for (char c : s) {
    charCount[c]++;
  }

  // Count the number of odd-frequency characters.
  int oddCount = 0;
  for (auto& [c, count] : charCount) {
    if (count % 2 == 1) {
      oddCount++;
    }
  }

  // If there are more than k odd-frequency characters, then it is
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
