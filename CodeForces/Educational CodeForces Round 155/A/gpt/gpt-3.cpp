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
        vector<pair<int, int>> athletes;
        
        for (int i = 0; i < n; i++) {
            int s, e;
            cin >> s >> e;
            athletes.push_back({s, e});
        }
        
        sort(athletes.begin(), athletes.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;
        });
        
        int w = athletes[0].first;
        int total_endurance = athletes[0].second;
        int max_lifts = 1;
        bool possible = false;
        
        for (int i = 1; i < n; i++) {
            if (athletes[i].first >= w) {
                possible = true;
                break;
            }
            
            total_endurance += athletes[i].second;
            if (total_endurance <= 0) {
                possible = false;
                break;
            }
            
            max_lifts++;
        }
        
        if (possible) {
            cout << w + 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}
