#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> cards(n);
        for (int i = 0; i < n; ++i) {
            cin >> cards[i];
        }
        
        long long odd_sum = 0;
        long long even_sum = 0;
        long long total_sum = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                even_sum += cards[i];
            } else {
                odd_sum += cards[i];
            }
            total_sum += cards[i];
        }
        
        long long max_score = max(even_sum, total_sum - odd_sum);
        
        cout << max_score << endl;
    }
    
    return 0;
}
