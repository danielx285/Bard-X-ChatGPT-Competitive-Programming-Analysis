#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a;
        a.push_back(1);
        a.push_back(2);
        
        for (int i = 2; i < n; i++) {
            int next = a[i - 1] + a[i - 2];
            a.push_back(next);
        }
        
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}
