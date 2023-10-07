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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        vector<int> maxRight(n);
        maxRight[n - 1] = a[n - 1];
        
        for (int i = n - 2; i >= 0; --i) {
            maxRight[i] = max(maxRight[i + 1], a[i]);
        }
        
        int q;
        cin >> q;
        
        while (q--) {
            int l, k;
            cin >> l >> k;
            
            int left = l - 1;  // Convert to 0-based index
            int right = n - 1;
            int ans = -1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                
                if ((a[left] & a[mid]) >= k) {
                    ans = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            // Convert back to 1-based index
            cout << ans + 1 << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}
