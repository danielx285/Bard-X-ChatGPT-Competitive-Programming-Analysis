#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s) {
  int i = 0, j = s.size() - 1;
  while (i < j) {
    if (s[i] != s[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

bool canRearrangeToPalindrome(string s, int k) {
  vector<int> count(26, 0);
  for (char c : s) {
    count[c - 'a']++;
  }

  int oddCount = 0;
  for (int i = 0; i < 26; i++) {
    if (count[i] % 2 == 1) {
      oddCount++;
    }
  }

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

    if (canRearrangeToPalindrome(s, k)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
