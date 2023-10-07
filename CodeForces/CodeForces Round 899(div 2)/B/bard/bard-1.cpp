#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<set<int>> sets(n);
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int si;
                cin >> si;
                sets[i].insert(si);
            }
        }

        int max_size = 0;
        for (int i = 0; i < (1 << n); i++) {
            set<int> s;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    s.insert(sets[j].begin(), sets[j].end());
                }
            }

            if (s != sets[0] && s.size() > max_size) {
                max_size = s.size();
            }
        }

        cout << max_size << endl;
    }

    return 0;
}
