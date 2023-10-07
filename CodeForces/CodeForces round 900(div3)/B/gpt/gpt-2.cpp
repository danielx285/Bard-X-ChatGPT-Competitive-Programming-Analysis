#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> result;
        result.push_back(1);
        
        for (int i = 1; i < n; i++) {
            int next = result.back() * 3 + 2;
            result.push_back(next);
        }
        
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}
