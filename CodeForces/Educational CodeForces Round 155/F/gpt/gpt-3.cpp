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
        vector<long long> max_points(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        vector<pair<long long, int>> damage_order;
        
        for (int i = 0; i < n; ++i) {
            damage_order.emplace_back(a[i], i);
        }
        
        sort(damage_order.begin(), damage_order.end(), greater<pair<long long, int>>());
        
        long long current_damage = 0;
        
        for (int i = 0; i < n; ++i) {
            int hero_index = damage_order[i].second;
            current_damage += a[hero_index];
            max_points[hero_index] = max(max_points[hero_index], (current_damage + h[hero_index] - 1) / h[hero_index]);
        }
        
        for (int i = 0; i < n; ++i) {
            cout << max_points[i] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}
