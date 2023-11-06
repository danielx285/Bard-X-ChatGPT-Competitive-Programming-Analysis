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
        
        int min_b = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] > min_b) {
                cout << min_b << endl;
                break;
            }
            min_b = max(min_b, a[i]) + 1;
            if (i == n - 1) {
                cout << min_b << endl;
            }
        }
    }
    
    return 0;
}
