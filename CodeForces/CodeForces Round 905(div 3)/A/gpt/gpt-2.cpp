#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string pin;
        cin >> pin;

        int seconds = 0;
        int current_digit = 1;

        for (char c : pin) {
            int target_digit = c - '0';
            if (current_digit == target_digit) {
                seconds += 1; // Pressing the cursor
            } else {
                int diff = abs(current_digit - target_digit);
                seconds += min(diff, 10 - diff); // Moving the cursor
                seconds += 1; // Pressing the cursor
            }

            current_digit = target_digit;
        }

        cout << seconds << endl;
    }

    return 0;
}
