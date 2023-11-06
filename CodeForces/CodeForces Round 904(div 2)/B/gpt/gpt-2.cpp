#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        // Initialize an array to store the minimum operations for each i
        vector<int> min_ops(n + 1, -1);

        // Find the rightmost position of '1' in the binary string
        int last_one_pos = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                last_one_pos = i;
            }
        }

        // Calculate minimum operations for i from 1 to n
        for (int i = 1; i <= n; i++) {
            if (s[n - i] == '1') {
                min_ops[i] = 0;
            } else if (last_one_pos >= i - 1) {
                // If there is a '1' to the left, swap it rightwards to make it reachable
                min_ops[i] = i - 1;
            }
        }

        // Output the results
        for (int i = 1; i <= n; i++) {
            cout << min_ops[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
