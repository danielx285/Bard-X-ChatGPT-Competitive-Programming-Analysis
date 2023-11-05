#include <iostream>

using namespace std;

int main() {

  int x;
  cin >> x;

  if (x < 3) {
    cout << "GOLD";
  } else if (x < 6) {
    cout << "SILVER";
  } else {
    cout << "BRONZE";
  }

  return 0;
}
