#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        if (a[n - 1] - a[0] <= k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
