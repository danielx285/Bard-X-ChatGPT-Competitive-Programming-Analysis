#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  // Check if Dhoni received the maximum number of votes.
  if (a > b && a > c) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
