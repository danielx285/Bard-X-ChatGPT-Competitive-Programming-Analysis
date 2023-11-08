#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, x, d;
    cin >> n >> x >> d;

    // Total number of days the family can survive.
    int days = n / (x * 5) + d;

    // If the number of buns is not enough to feed everyone, nobody will eat anything.
    if (n < x * 5) {
      days = d;
    }

    cout << days << endl;
  }

  return 0;
}
