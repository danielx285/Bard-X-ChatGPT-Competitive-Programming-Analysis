#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        long long x;
        cin >> n >> k >> x;

        // If k is 1 or k is equal to n, the answer is YES if x is in the range [1, n]
        if (k == 1 || k == n) {
            if (x >= 1 && x <= n) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            // If k is greater than n or k is odd and x is even, it's impossible
            if (k > n || (k % 2 != 0 && x % 2 == 0)) {
                cout << "NO" << endl;
            } else {
                // Use a set to keep track of chosen numbers
                set<int> chosen;

                // Add the numbers 1 to k-2 to the set
                for (int i = 1; i <= k - 2; i++) {
                    chosen.insert(i);
                }

                // Calculate the remaining sum
                long long remaining_sum = x - (k - 1);

                // Add the remaining numbers from n down to k
                for (int i = n; i >= k; i--) {
                    if (remaining_sum <= 0) {
                        break;
                    }
                    if (chosen.find(i) == chosen.end()) {
                        chosen.insert(i);
                        remaining_sum -= i;
                    }
                }

                // If the remaining sum is 0 and we have exactly k numbers, it's possible
                if (remaining_sum == 0 && chosen.size() == k) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        }
    }

    return 0;
}
