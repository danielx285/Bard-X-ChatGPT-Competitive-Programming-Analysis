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
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        // Check if it's possible to make the array good
        bool possible = true;
        int target_sum = a[0] + a[n - 1];
        
        for (int i = 0; i < n - 1; i++) {
            if (a[i] + a[i + 1] != target_sum) {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
