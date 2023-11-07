#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    set<pair<int, int>> segments;

    while (q--) {
        char operation;
        cin >> operation;
        int l, r;
        cin >> l >> r;

        if (operation == '+') {
            segments.insert({l, r});
        } else {
            segments.erase({l, r});
        }

        bool found = false;
        for (auto it1 = segments.begin(); it1 != segments.end(); ++it1) {
            for (auto it2 = next(it1); it2 != segments.end(); ++it2) {
                if (it1->second < it2->first || it2->second < it1->first) {
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
