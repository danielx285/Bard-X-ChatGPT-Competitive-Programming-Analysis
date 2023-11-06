#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to calculate the bitwise AND of elements in the range [l, r]
int calculateAND(vector<int>& a, int l, int r) {
    int result = a[l - 1];
    for (int i = l; i <= r; i++) {
        result &= a[i - 1];
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int q;
        cin >> q;

        // Precompute the maximum right index for each position
        vector<int> maxRightIndex(n);
        maxRightIndex[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            maxRightIndex[i] = (a[i] & a[i + 1]) == a[i + 1] ? maxRightIndex[i + 1] : i;
        }

        while (q--) {
            int l, k;
            cin >> l >> k;

            int low = l - 1, high = n - 1, result = -1;

            while (low <= high) {
                int mid = (low + high) / 2;
                if (calculateAND(a, l, mid + 1) >= k) {
                    result = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (result == -1 || maxRightIndex[l - 1] < result) {
                cout << -1 << " ";
            } else {
                cout << result + 1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
