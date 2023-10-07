#include <iostream>
#include <vector>
#include <unordered_map>

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

        int maxCount = 0;
        unordered_map<int, int> count;
        bool found = false;

        for (int left = 0, right = 0; right < n; right++) {
            count[a[right]]++;

            maxCount = max(maxCount, count[a[right]]);

            while (right - left + 1 - maxCount > k) {
                count[a[left]]--;
                left++;
            }

            if (right - left + 1 - maxCount <= k) {
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
