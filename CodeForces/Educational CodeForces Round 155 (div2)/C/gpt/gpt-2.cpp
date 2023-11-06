#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        int n = s.size();
        
        vector<int> zeros(n), ones(n);
        
        // Count the number of 0's and 1's from left to right
        zeros[0] = (s[0] == '0');
        ones[0] = (s[0] == '1');
        
        for (int i = 1; i < n; i++) {
            zeros[i] = zeros[i - 1] + (s[i] == '0');
            ones[i] = ones[i - 1] + (s[i] == '1');
        }
        
        int min_operations = min(zeros[n - 1], ones[n - 1]);
        int num_sequences = 1;
        
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                if (s[i - 1] == '1') {
                    // To make it alternating, delete the previous '1'
                    min_operations++;
                }
            } else {
                if (s[i - 1] == '0') {
                    // To make it alternating, delete the previous '0'
                    min_operations++;
                }
            }
        }
        
        // Count the number of different shortest sequences of operations
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                num_sequences++;
            }
        }
        
        cout << min_operations << " " << num_sequences % MOD << endl;
    }
    
    return 0;
}
