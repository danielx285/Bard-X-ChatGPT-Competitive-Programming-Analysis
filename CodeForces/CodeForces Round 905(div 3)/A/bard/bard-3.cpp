#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string pin;
    cin >> pin;

    int current_digit = 1;
    int seconds = 0;

    for (char digit : pin) {
      int distance = abs(digit - current_digit);

      // If the distance is greater than 1, move the cursor to the
      // adjacent digit.
      if (distance > 1) {
        seconds += distance - 1;
      }

      // Press the cursor.
      seconds++;

      // Update the current digit.
      current_digit = digit;
    }

    cout << seconds << endl;
  }

  return 0;
}
