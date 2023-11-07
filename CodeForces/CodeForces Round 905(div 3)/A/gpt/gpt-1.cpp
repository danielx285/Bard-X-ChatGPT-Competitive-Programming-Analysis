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
        int current_digit = 1;  // Start at digit 1

        for (char c : pin) {
            int target_digit = c - '0';

            int diff = abs(target_digit - current_digit);
            seconds += min(diff, 10 - diff); // Choose the shortest direction

            current_digit = target_digit;
        }

        cout << seconds << endl;
    }

    return 0;
}
