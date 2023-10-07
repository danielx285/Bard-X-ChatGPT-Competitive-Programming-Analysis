#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reverseSubstring(string& s, int a, int b) {
    while (a < b) {
        swap(s[a], s[b]);
        a++;
        b--;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, q;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> l(k), r(k);

        for (int i = 0; i < k; i++) {
            cin >> l[i];
        }

        for (int i = 0; i < k; i++) {
            cin >> r[i];
        }

        cin >> q;

        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            int index = -1;

            for (int j = 0; j < k; j++) {
                if (l[j] <= x && x <= r[j]) {
                    index = j;
                    break;
                }
            }

            if (index != -1) {
                int a = min(x, r[index] + l[index] - x);
                int b = max(x, r[index] + l[index] - x);
                reverseSubstring(s, a - 1, b - 1);
            }
        }

        cout << s << endl;
    }

    return 0;
}
