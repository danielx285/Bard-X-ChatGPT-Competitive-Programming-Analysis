#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <algorithm>

using namespace std;

const int MAX_N = 50;
const int MAX_K = 50;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<int>> sets(n);
        set<int> elements;
        
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                sets[i].push_back(x);
                elements.insert(x);
            }
        }
        
        int max_attainable = 0;
        
        // Iterate over all possible subsets of sets
        for (int mask = 1; mask < (1 << n); mask++) {
            set<int> attainable;
            
            // Take the union of selected sets
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    for (int x : sets[i]) {
                        attainable.insert(x);
                    }
                }
            }
            
            // Check if the union is not equal to all elements
            if (attainable != elements) {
                int size = attainable.size();
                max_attainable = max(max_attainable, size);
            }
        }
        
        cout << max_attainable << endl;
    }
    
    return 0;
}
