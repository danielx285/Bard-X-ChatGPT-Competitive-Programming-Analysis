#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k, x;
        cin >> n >> k >> x;

        // Check if it's possible to choose k distinct integers between 1 and n
        // such that their sum is equal to x
        if (k > n || x < k || x > k * n - k * (k - 1) / 2) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
