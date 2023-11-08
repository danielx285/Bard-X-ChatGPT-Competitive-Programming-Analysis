#include <iostream>

using namespace std;

int main() {
  long long b;
  cin >> b;

  for (long long a = 1; a * a <= b; a++) {
    if (a * a == b) {
      cout << a << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}
