#include <iostream>
#include <vector>

using namespace std;

bool isOddPrimeFactor(int n, int p) {
  return p % 2 == 1 && n % p == 0;
}

bool canAliceMove(int n) {
  for (int i = 3; i * i <= n; i += 2) {
    if (isOddPrimeFactor(n, i)) {
      return true;
    }
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    if (canAliceMove(n)) {
      cout << "Alice" << endl;
    } else {
      cout << "Bob" << endl;
    }
  }
  return 0;
}
