#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, k;
        cin >> x >> k;

        // Find the smallest integer y >= x which is k-beautiful
        int y = x;
        while (true) {
            int sum = 0;
            int temp = y;

            // Calculate the digit sum of y
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }

            // Check if the digit sum is divisible by k
            if (sum % k == 0) {
                cout << y << endl;
                break;
            }

            y++;
        }
    }

    return 0;
}
