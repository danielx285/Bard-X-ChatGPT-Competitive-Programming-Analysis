#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;

    int max_neighbours = 0;
    for (int i = 1; i <= x; i++) {
      if (i % y == 0) {
        max_neighbours++;
      }
    }

    cout << max_neighbours << endl;
  }

  return 0;
}
