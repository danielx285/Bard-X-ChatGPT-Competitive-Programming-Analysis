#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    multiset<pair<int, int>> segments;
    multiset<int> endpoints;

    for (int i = 0; i < q; i++) {
        char op;
        cin >> op;

        if (op == '+') {
            int l, r;
            cin >> l >> r;
            segments.insert({l, r});
            endpoints.insert(l);
            endpoints.insert(r);
        } else {
            int l, r;
            cin >> l >> r;
            segments.erase(segments.find({l, r}));
        }

        bool found = false;
        for (auto it = segments.begin(); it != segments.end(); ++it) {
            auto next = it;
            ++next;
            if (next != segments.end() && it->second < next->first) {
                found = true;
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
