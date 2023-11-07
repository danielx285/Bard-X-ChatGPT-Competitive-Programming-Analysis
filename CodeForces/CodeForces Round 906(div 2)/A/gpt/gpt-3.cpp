#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isGoodArray(vector<int> &a) {
    int n = a.size();
    sort(a.begin(), a.end()); // Sort the array in ascending order.

    int k = a[1] - a[0]; // Calculate the expected sum of two adjacent elements.

    for (int i = 1; i < n - 1; i++) {
        if (a[i + 1] - a[i] != k) {
            return false; // If any pair of adjacent elements doesn't have the expected sum, it's not a good array.
        }
    }

    return true;
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

        if (isGoodArray(a)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
