#include <iostream>
#include <vector>
#include <map>

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
        
        map<int, int> count; // To count occurrences of each element
        long long goodPairs = 0; // To store the number of good pairs
        
        for (int i = 0; i < n; i++) {
            goodPairs += count[a[i]]; // Add the count of occurrences to the result
            
            for (int j = i + 1; j < n; j++) {
                if (a[j] % a[i] == 0) {
                    count[a[j]]++; // Increment the count of elements that are divisible by a[i]
                }
            }
        }
        
        cout << goodPairs << endl;
    }
    
    return 0;
}
