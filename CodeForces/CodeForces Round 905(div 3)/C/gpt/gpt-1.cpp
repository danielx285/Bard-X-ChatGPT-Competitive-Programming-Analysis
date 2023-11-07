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

        int operations = 0;
        for (int i = 0; i < n; i++) {
            int remainder = a[i] % k;
            if (remainder != 0) {
                int required = k - remainder;
                a[i] += required;
                operations += required;
            }
        }

        long long product = 1;
        for (int i = 0; i < n; i++) {
            product *= a[i];
        }

        int additional_operations = 0;
        while (product % k != 0) {
            product *= k;
            additional_operations++;
        }

        operations += additional_operations;

        cout << operations << endl;
    }

    return 0;
}
