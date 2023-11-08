#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    // There are n possibilities for the captain, and n-1 possibilities for the vice-captain,
    // but we must avoid overcounting cases where the captain is chosen as the vice-captain,
    // so we subtract 1.
    cout << n * (n - 1) - 1 << endl;
  }

  return 0;
}
