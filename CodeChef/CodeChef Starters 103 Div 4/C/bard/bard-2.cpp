#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

    int alice_score = max(a1 * 100 + a2 * 10 + a3, max(a2 * 100 + a3 * 10 + a1, a3 * 100 + a1 * 10 + a2));
    int bob_score = max(b1 * 100 + b2 * 10 + b3, max(b2 * 100 + b3 * 10 + b1, b3 * 100 + b1 * 10 + b2));

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
