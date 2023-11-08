#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long B;
    cin >> B;

    // If B is 1, then the result is also 1
    if (B == 1) {
        cout << 1 << endl;
        return 0;
    }

    // Iterate from 2 to the square root of B
    for (long long A = 2; A * A <= B; ++A) {
        long long power = A;
        while (power * A <= B) {
            power *= A;
        }
        if (power == B) {
            cout << A << endl;
            return 0;
        }
    }

    cout << -1 << endl;  // No such A found
    return 0;
}
