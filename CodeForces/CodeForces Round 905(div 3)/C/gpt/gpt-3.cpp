#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        
        int min_operations = 0;
        int product = 1;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            product *= a[i];
        }
        
        if (product % k != 0) {
            int remaining = k - (product % k);
            for (int i = 0; i < n; i++) {
                if (remaining == 0) break;
                int diff = k - (a[i] % k);
                if (diff <= remaining) {
                    remaining -= diff;
                    min_operations += diff;
                }
            }
        }
        
        cout << min_operations << endl;
    }
    
    return 0;
}
