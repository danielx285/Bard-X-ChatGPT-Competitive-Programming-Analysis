#include <iostream>
#include <string>

using namespace std;

int minSecondsToEnterPin(string pin) {
  int seconds = 0;
  int currentDigit = 1;

  for (int i = 0; i < pin.length(); i++) {
    // If the current digit is not the same as the next digit in the pin,
    // move the cursor to the next digit.
    if (currentDigit != pin[i]) {
      seconds++;
      currentDigit = pin[i];
    }

    // Press the cursor to enter the digit.
    seconds++;
  }

  return seconds;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    string pin;
    cin >> pin;

    cout << minSecondsToEnterPin(pin) << endl;
  }

  return 0;
}
