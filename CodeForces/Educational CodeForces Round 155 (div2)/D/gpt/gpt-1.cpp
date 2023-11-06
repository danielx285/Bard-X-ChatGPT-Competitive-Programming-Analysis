#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    for (int l = 0; l < n; l++) {
        int xor_val = 0;
        for (int r = l; r < n; r++) {
            xor_val ^= a[r];
            ans = (ans + (long long)(r - l + 1) * xor_val) % MOD;
        }
    }

    cout << ans << endl;
    
    return 0;
}
