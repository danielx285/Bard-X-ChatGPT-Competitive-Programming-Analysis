#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<long long> count(n + 1, 0);  // Initialize count array with zeros
        map<int, long long> divisibleCount;  // Store counts of divisible numbers

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[j] % a[i] == 0) {
                    // If a[j] is divisible by a[i], increment count[a[i]]
                    ans += count[a[i]];
                }
            }
            // Increment count[a[i]] and store it in divisibleCount
            count[a[i]]++;
            divisibleCount[a[i]] += count[a[i]];
        }

        cout << ans << endl;
    }

    return 0;
}
