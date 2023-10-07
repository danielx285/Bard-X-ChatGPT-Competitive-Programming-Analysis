#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, k, x;
        cin >> n >> k >> x;
        
        long long min_sum = (k * (k + 1)) / 2;  // Minimum possible sum of k distinct integers
        
        if (min_sum > x) {
            cout << "NO" << endl;
        } else {
            long long max_sum = (n * (n + 1)) / 2 - (n - k) * (n - k + 1) / 2;  // Maximum possible sum of k distinct integers
            
            if (max_sum < x) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }
    
    return 0;
}
