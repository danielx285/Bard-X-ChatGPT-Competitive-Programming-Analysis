#include <iostream>
#include <vector>

using namespace std;

// Function to find the smallest prime factor of a number
int smallestPrimeFactor(int n) {
    if (n <= 1) return 0;

    while (n % 2 == 0) {
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            return i;
        }
    }

    if (n > 1) {
        return n;
    }

    return 0;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        // Count the number of prime factors
        vector<int> factors;
        int numFactors = 0;
        int tempN = N;
        while (tempN > 1) {
            int factor = smallestPrimeFactor(tempN);
            if (factor == 0) {
                break;
            }
            factors.push_back(factor);
            tempN -= factor;
            numFactors++;
        }

        if (numFactors % 2 == 0) {
            // If the number of factors is even, Alice wins
            cout << "Alice" << endl;
        } else {
            // If the number of factors is odd, Bob wins
            cout << "Bob" << endl;
        }
    }

    return 0;
}
