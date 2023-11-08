#include <iostream>
#include <string>

using namespace std;

bool hasAdjacentAB(const string& s) {
  for (int i = 0; i < s.length() - 1; i++) {
    if ((s[i] == 'a' && s[i + 1] == 'b') || (s[i] == 'b' && s[i + 1] == 'a')) {
      return true;
    }
  }
  return false;
}

int main() {
  int N;
  string S;
  cin >> N >> S;

  if (hasAdjacentAB(S)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
