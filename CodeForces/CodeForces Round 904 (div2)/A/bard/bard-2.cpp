#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, k;
    cin >> x >> k;
    int y = x;
    while (!((y - x) % k == 0)) {
      y++;
    }
    cout << y << endl;
  }
  return 0;
}
