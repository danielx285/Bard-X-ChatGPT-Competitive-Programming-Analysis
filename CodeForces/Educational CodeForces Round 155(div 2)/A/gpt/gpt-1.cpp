#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<pair<int, int>> athletes(n);
        
        for (int i = 0; i < n; i++) {
            cin >> athletes[i].first >> athletes[i].second;
        }
        
        int best_w = -1;
        int max_lifts = -1;
        
        for (int w = 1; w <= 1000000; w++) {  // You can adjust the upper bound for w as needed
            int lifts = 0;
            
            for (int i = 0; i < n; i++) {
                if (athletes[i].first >= w) {
                    lifts += athletes[i].second;
                }
            }
            
            if (lifts > max_lifts) {
                max_lifts = lifts;
                best_w = w;
            }
        }
        
        cout << best_w << endl;
    }
    
    return 0;
}
