#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int minSecondsToEnterPin(string pin) {
    int seconds = 0;
    int currentDigit = 1;

    for (int i = 0; i < 4; i++) {
        int targetDigit = pin[i] - '0';

        if (currentDigit == targetDigit) {
            seconds++;  // Press the cursor
        } else {
            int clockwise = (currentDigit + 1) % 10;
            int counterclockwise = (currentDigit - 1 + 10) % 10;

            int clockwiseDistance = abs(clockwise - targetDigit);
            int counterclockwiseDistance = abs(counterclockwise - targetDigit);

            if (clockwiseDistance <= counterclockwiseDistance) {
                seconds += clockwiseDistance + 1;  // Move cursor clockwise and press
            } else {
                seconds += counterclockwiseDistance + 1;  // Move cursor counterclockwise and press
            }
        }

        currentDigit = targetDigit;
    }

    return seconds;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pin;
        cin >> pin;
        int seconds = minSecondsToEnterPin(pin);
        cout << seconds << endl;
    }
    return 0;
}
