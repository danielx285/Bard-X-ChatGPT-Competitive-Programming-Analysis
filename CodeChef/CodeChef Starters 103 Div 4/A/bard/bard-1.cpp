#include <iostream>

using namespace std;

int main() {
  int X;
  cin >> X;

  if (X < 3) {
    cout << "GOLD";
  } else if (X < 6) {
    cout << "SILVER";
  } else {
    cout << "BRONZE";
  }

  return 0;
}
