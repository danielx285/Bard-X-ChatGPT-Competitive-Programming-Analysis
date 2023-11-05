#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

    int aliceScore = (a1 * 100) + (a2 * 10) + a3;
    int bobScore = (b1 * 100) + (b2 * 10) + b3;

    if (aliceScore > bobScore) {
      cout << "Alice" << endl;
    } else if (aliceScore < bobScore) {
      cout << "Bob" << endl;
    } else {
      cout << "Tie" << endl;
    }
  }
  return 0;
}
