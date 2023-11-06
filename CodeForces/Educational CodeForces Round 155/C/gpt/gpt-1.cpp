#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.size();

        // Initialize variables to count consecutive equal characters
        int consecutive_zeros = 0;
        int consecutive_ones = 0;

        // Count the consecutive equal characters in the string
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                consecutive_zeros++;
                consecutive_ones = 0;
            } else {
                consecutive_ones++;
                consecutive_zeros = 0;
            }
        }

        // Calculate the minimum number of operations required
        int min_operations = min(consecutive_zeros, consecutive_ones);

        // Calculate the number of different shortest sequences of operations
        long long num_sequences = 1;
        for (int i = 0; i < min_operations; i++) {
            num_sequences = (num_sequences * 2) % MOD;
        }

        cout << min_operations << " " << num_sequences << endl;
    }

    return 0;
}
