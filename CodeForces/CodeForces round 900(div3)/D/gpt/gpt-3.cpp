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

        string s;
        cin >> s;

        vector<int> l(k);
        vector<int> r(k);

        for (int i = 0; i < k; i++) {
            cin >> l[i];
        }

        for (int i = 0; i < k; i++) {
            cin >> r[i];
        }

        int q;
        cin >> q;

        while (q--) {
            int x;
            cin >> x;
            x--;

            int i = lower_bound(l.begin(), l.end(), x + 1) - l.begin(); // Find the index i

            int a = min(x - l[i - 1] + 1, r[i] - x);
            int b = max(x - l[i - 1] + 1, r[i] - x);

            reverse(s.begin() + a - 1, s.begin() + b); // Reverse the substring [a, b]
        }

        cout << s << endl;
    }

    return 0;
}
