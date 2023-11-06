#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + (s[i] - '0');
        }

        for (int i = 1; i <= n; i++) {
            if ((n % i) == 0) {
                bool possible = true;
                int operations = 0;
                for (int j = 0; j < n; j += i) {
                    int ones = prefix_sum[j + i] - prefix_sum[j];
                    int zeros = i - ones;
                    if (ones != 0 && zeros != 0) {
                        possible = false;
                        break;
                    }
                    operations += min(ones, zeros);
                }
                if (possible) {
                    cout << operations << " ";
                } else {
                    cout << "-1 ";
                }
            } else {
                cout << "-1 ";
            }
        }
        cout << "\n";
    }

    return 0;
}
