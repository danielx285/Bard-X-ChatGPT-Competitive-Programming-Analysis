#include <iostream>

using namespace std;

bool isDhoniWinner(int A, int B, int C) {
  return A > B && A > C;
}

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  if (isDhoniWinner(A, B, C)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
