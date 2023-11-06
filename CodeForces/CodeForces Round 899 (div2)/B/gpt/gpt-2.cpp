#include <iostream>
#include <vector>
#include <set>
#include <bitset>

using namespace std;

const int MAX_N = 51;
const int MAX_K = 51;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<bitset<MAX_N>> sets(n);
        
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                sets[i].set(x);
            }
        }

        int max_elements = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            bitset<MAX_N> union_set;
            int elements = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    union_set |= sets[i];
                }
            }

            for (int i = 1; i < MAX_N; i++) {
                if (union_set.test(i)) {
                    elements++;
                }
            }

            if (elements > max_elements) {
                max_elements = elements;
            }
        }

        cout << max_elements << endl;
    }

    return 0;
}
