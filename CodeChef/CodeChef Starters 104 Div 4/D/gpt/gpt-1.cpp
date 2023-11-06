#include <iostream>
#include <algorithm>

using namespace std;

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate the least common multiple (LCM) of two numbers
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;

        int common = gcd(x, y); // Initial GCD
        int minSum = x + y;     // Initial sum of numbers

        if (k % 2 == 0) {
            // If K is even, the GCD and LCM will always be the same, and the numbers remain unchanged.
            cout << minSum << endl;
        } else {
            // If K is odd, perform one operation and update the numbers accordingly.
            x = gcd(x, y);
            y = lcm(x, y);

            // Calculate the new minimum sum after the operation
            minSum = x + y;

            cout << minSum << endl;
        }
    }

    return 0;
}
