#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k, q;
        cin >> n >> k;
        
        string s;
        cin >> s;
        
        vector<int> l(k), r(k);
        for (int i = 0; i < k; i++) {
            cin >> l[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> r[i];
        }
        
        cin >> q;
        
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            int idx = 0;
            
            for (int j = 0; j < k; j++) {
                if (l[j] <= x && x <= r[j]) {
                    idx = j;
                    break;
                }
            }
            
            int a = min(x, r[idx] + l[idx] - x);
            int b = max(x, r[idx] + l[idx] - x);
            
            reverse(s.begin() + a - 1, s.begin() + b);
        }
        
        cout << s << endl;
    }
    
    return 0;
}
