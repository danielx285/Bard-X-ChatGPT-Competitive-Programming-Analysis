#include <iostream>
#include <vector>

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

        int ops = 0;
        int remaining_mod[k] = {0};
        for (int i = 0; i < n; i++) {
            a[i] %= k;
            remaining_mod[a[i]]++;
        }

        for (int i = 1; i < k; i++) {
            int opposite_mod = (k - i) % k;
            if (i != opposite_mod) {
                if (remaining_mod[i] > remaining_mod[opposite_mod]) {
                    remaining_mod[i] -= remaining_mod[opposite_mod];
                    remaining_mod[opposite_mod] = 0;
                } else {
                    remaining_mod[opposite_mod] -= remaining_mod[i];
                    remaining_mod[i] = 0;
                }
            }
        }

        for (int i = 0; i < k; i++) {
            int j = (k - i) % k;
            if (i != j) {
                if (remaining_mod[i] > 0) {
                    ops += max(0, (remaining_mod[i] - 1) / (k - 1)) * 2;
                    if (remaining_mod[i] % (k - 1) == 0) {
                        ops++;
                    }
                }
            } else if (i == 0) {
                if (remaining_mod[i] > 0) {
                    ops++;
                }
            }
        }

        cout << ops << endl;
    }
    return 0;
}
