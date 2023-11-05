#include <iostream>

using namespace std;

int main() {
  int time;
  cin >> time;

  string medal;
  if (time < 3) {
    medal = "GOLD";
  } else if (time < 6) {
    medal = "SILVER";
  } else {
    medal = "BRONZE";
  }

  cout << medal << endl;

  return 0;
}
