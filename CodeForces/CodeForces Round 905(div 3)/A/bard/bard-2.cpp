#include <iostream>
#include <vector>

using namespace std;

int minSecondsToEnterPinCode(string pinCode) {
  // Initialize a vector to store the number of seconds required to enter each digit of the pin code.
  vector<int> seconds(4, 0);

  // Calculate the number of seconds required to enter the first digit.
  seconds[0] = 1;

  // Iterate over the remaining digits of the pin code.
  for (int i = 1; i < 4; i++) {
    // Calculate the number of seconds required to move the cursor to the current digit.
    int secondsToMoveToCurrentDigit = 0;
    if (pinCode[i] > pinCode[i - 1]) {
      secondsToMoveToCurrentDigit = pinCode[i] - pinCode[i - 1];
    } else {
      secondsToMoveToCurrentDigit = 10 - (pinCode[i - 1] - pinCode[i]);
    }

    // Calculate the total number of seconds required to enter the current digit.
    seconds[i] = seconds[i - 1] + secondsToMoveToCurrentDigit + 1;
  }

  // Return the total number of seconds required to enter the pin code.
  return seconds[3];
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    string pinCode;
    cin >> pinCode;

    cout << minSecondsToEnterPinCode(pinCode) << endl;
  }

  return 0;
}
