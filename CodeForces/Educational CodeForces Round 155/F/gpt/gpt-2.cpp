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
        
        vector<int> h(n);
        vector<int> a(n);
        vector<pair<int, int>> heroes;
        
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            heroes.push_back({a[i], h[i]});
        }
        
        sort(heroes.rbegin(), heroes.rend());
        
        long long total_damage = 0;
        long long max_points = 0;
        
        for (int i = 0; i < n; i++) {
            total_damage += heroes[i].second;
            max_points = max(max_points, (total_damage + heroes[i].first - 1) / heroes[i].first);
        }
        
        vector<long long> points(n);
        
        for (int i = 0; i < n; i++) {
            points[i] = max_points;
            if (i > 0) {
                long long prev_damage = total_damage - heroes[i].second;
                points[i] = max(points[i], (prev_damage + heroes[i].first - 1) / heroes[i].first);
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << points[i] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}
