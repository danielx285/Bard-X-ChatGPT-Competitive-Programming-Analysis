#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> ans;
        
        // The first element of the array can be any positive integer
        ans.push_back(1);
        
        // Initialize a variable to keep track of the previous element
        int prev = 1;
        
        // Start from the second element and construct the array
        for (int i = 1; i < n; i++) {
            // Find the next element by multiplying the previous element by 2
            int next = prev * 2;
            
            // Ensure the condition 3*ai+2 is not divisible by ai+ai+1
            while (next % (prev + prev) == 0) {
                next++;
            }
            
            ans.push_back(next);
            prev = next;
        }
        
        // Output the array elements
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}
