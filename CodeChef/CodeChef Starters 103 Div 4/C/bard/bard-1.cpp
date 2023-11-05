#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

    int alice_score = max(a1 * 100 + a2 * 10 + a3, a3 * 100 + a2 * 10 + a1);
    int bob_score = max(b1 * 100 + b2 * 10 + b3, b3 * 100 + b2 * 10 + b1);

    if (alice_score > bob_score) {
      cout << "Alice" << endl;
    } else if (bob_score > alice_score) {
      cout << "Bob" << endl;
    } else {
      cout << "Tie" << endl;
    }
  }

  return 0;
}
