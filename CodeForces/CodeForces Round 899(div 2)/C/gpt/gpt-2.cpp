#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long even_sum = 0;
        long long odd_sum = 0;

        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                even_sum += max(a[i], 0LL);
            } else {
                odd_sum += max(a[i], 0LL);
            }
        }

        long long max_score = max(even_sum, odd_sum);
        cout << max_score << endl;
    }

    return 0;
}
