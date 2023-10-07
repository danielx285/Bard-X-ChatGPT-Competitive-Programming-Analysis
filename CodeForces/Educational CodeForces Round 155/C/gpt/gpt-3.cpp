#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 998244353
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        int n = s.size();
        vector<int> prefix_count(n, 0);
        
        // Count the number of '0's in the prefix of the string
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0) {
                    prefix_count[i] = prefix_count[i - 1] + 1;
                } else {
                    prefix_count[i] = 1;
                }
            } else {
                if (i > 0) {
                    prefix_count[i] = prefix_count[i - 1];
                }
            }
        }
        
        long long min_operations = n; // Maximum possible operations
        long long num_sequences = 1; // At least one sequence (no operation)
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                int zeros_in_prefix = prefix_count[i];
                int ones_in_suffix = (n - 1 - i) - (prefix_count[n - 1] - prefix_count[i]);
                int total_operations = zeros_in_prefix + ones_in_suffix;
                
                if (total_operations < min_operations) {
                    min_operations = total_operations;
                    num_sequences = 1;
                } else if (total_operations == min_operations) {
                    num_sequences++;
                }
            }
        }
        
        cout << min_operations << " " << num_sequences << endl;
    }
    
    return 0;
}
