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
        
        int min_b = a[n - 1] + 1;
        
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] >= min_b) {
                min_b--;
            } else {
                min_b = a[i];
            }
            
            if (min_b <= 0) {
                min_b = 1;
                break;
            }
        }
        
        cout << min_b << endl;
    }
    
    return 0;
}
