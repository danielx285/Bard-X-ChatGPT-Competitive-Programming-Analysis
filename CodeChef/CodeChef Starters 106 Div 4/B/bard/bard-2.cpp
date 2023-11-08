#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, X, D;
    cin >> N >> X >> D;

    // Calculate the total number of days the family can survive
    // by eating the buns.
    int days = N / X;

    // If there aren't enough buns to feed the whole family,
    // nobody will eat anything and the family will only survive
    // for D days.
    if (N < X * 5) {
      days = D;
    }

    cout << days << endl;
  }
  return 0;
}
