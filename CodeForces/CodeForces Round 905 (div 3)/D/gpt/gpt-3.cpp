#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int q;
        cin >> q;

        set<pair<int, int>> segments;
        vector<int> is_removed;
        bool has_disjoint_segments = false;

        for (int i = 0; i < q; i++) {
            char op;
            int l, r;
            cin >> op >> l >> r;

            if (op == '+') {
                segments.insert({l, r});
                is_removed.push_back(0);

                if (!has_disjoint_segments) {
                    for (int j = is_removed.size() - 1; j >= 0; j--) {
                        if (!is_removed[j] && (l > segments.rbegin()->second || r < segments.begin()->first)) {
                            has_disjoint_segments = true;
                            break;
                        }
                    }
                }
            } else {
                int index = -1;
                for (int j = 0; j < is_removed.size(); j++) {
                    if (!is_removed[j] && segments[j] == make_pair(l, r)) {
                        index = j;
                        is_removed[j] = 1;
                        break;
                    }
                }

                if (!has_disjoint_segments) {
                    for (int j = is_removed.size() - 1; j >= 0; j--) {
                        if (!is_removed[j] && (l > segments.rbegin()->second || r < segments.begin()->first)) {
                            has_disjoint_segments = true;
                            break;
                        }
                    }
                }
            }

            if (has_disjoint_segments) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
