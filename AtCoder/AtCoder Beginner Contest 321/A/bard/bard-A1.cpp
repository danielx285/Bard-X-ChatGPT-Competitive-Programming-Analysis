#include <iostream>

using namespace std;

bool is321Like(int n) {
  int prevDigit = n % 10;
  n /= 10;
  while (n > 0) {
    int currDigit = n % 10;
    if (currDigit >= prevDigit) {
      return false;
    }
    prevDigit = currDigit;
    n /= 10;
  }
  return true;
}

int main() {
  int n;
  cin >> n;

  if (is321Like(n)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
