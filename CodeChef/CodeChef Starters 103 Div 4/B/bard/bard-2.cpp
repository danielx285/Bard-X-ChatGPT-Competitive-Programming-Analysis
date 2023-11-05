#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int x, y;
    cin >> x >> y;

    int max_neighbors = x / y;

    cout << max_neighbors << endl;
  }

  return 0;
}
