#include <iostream>
#include <vector>

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

        int last = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < i + 1) {
                last = i + 1;
                break;
            }
        }

        cout << last + 1 << endl;
    }

    return 0;
}
