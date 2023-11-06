#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> a(m + 1, 0);  // Initialize an array of size m+1, where a[0] is unused.
        
        vector<pair<int, int>> segments;
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            segments.push_back(make_pair(l, r));
        }
        
        // Initialize prefix and suffix arrays to keep track of the segment values.
        vector<long long> prefix(m + 1, 0);
        vector<long long> suffix(m + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix[segments[i].first]++;
            suffix[segments[i].second]++;
        }
        
        // Calculate the segment values using prefix and suffix arrays.
        for (int i = 1; i <= m; i++) {
            prefix[i] += prefix[i - 1];
        }
        for (int i = m - 1; i >= 0; i--) {
            suffix[i] += suffix[i + 1];
        }
        
        // Calculate the cost for each possible subset of segments.
        long long max_cost = 0;
        long long current_value = 0;
        
        for (int i = 0; i < n; i++) {
            int l = segments[i].first;
            int r = segments[i].second;
            current_value += prefix[r] - prefix[l - 1];
            max_cost = max(max_cost, current_value);
        }
        
        // Calculate the final cost.
        long long min_a = 0, max_a = 0;
        for (int i = 1; i <= m; i++) {
            a[i] = current_value - suffix[i];
            min_a = min(min_a, a[i]);
            max_a = max(max_a, a[i]);
        }
        
        long long cost = max_a - min_a;
        cout << cost << endl;
    }
    
    return 0;
}
