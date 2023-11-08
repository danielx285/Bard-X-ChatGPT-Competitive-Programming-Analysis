#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long int ways = 1;
        for (int i = 1; i <= n; i++) {
            ways *= i;
        }

        ways = 2 * ways - 1;
        cout << ways << endl;
    }

    return 0;
}
