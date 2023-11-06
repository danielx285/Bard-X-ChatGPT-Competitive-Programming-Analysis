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
        
        int q;
        cin >> q;
        
        // Initialize a prefix array to store the bitwise AND of elements up to index i
        vector<int> prefix(n);
        prefix[0] = a[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] & a[i];
        }
        
        while (q--) {
            int l, k;
            cin >> l >> k;
            l--; // Adjust for 0-based indexing
            
            if (prefix[l] < k) {
                // If the bitwise AND of elements up to index l is less than k, it's impossible to find r
                cout << "-1 ";
            } else {
                int r = l;
                int result = a[l];
                
                // Keep checking for larger r values until the result is greater than or equal to k
                while (r < n && (result & a[r]) < k) {
                    result &= a[r];
                    r++;
                }
                
                if (r < n) {
                    cout << r + 1 << " "; // Convert back to 1-based indexing
                } else {
                    cout << "-1 ";
                }
            }
        }
        
        cout << "\n";
    }
    
    return 0;
}
