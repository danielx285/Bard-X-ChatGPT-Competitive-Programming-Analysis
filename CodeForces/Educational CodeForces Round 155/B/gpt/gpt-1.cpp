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
        
        vector<long long> a(n);
        vector<long long> b(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        vector<pair<long long, int>> rowCost(n);
        vector<pair<long long, int>> colCost(n);
        
        for (int i = 0; i < n; i++) {
            rowCost[i] = {a[i], i};
            colCost[i] = {b[i], i};
        }
        
        sort(rowCost.begin(), rowCost.end());
        sort(colCost.begin(), colCost.end());
        
        long long minCost = 0;
        long long rowChipCost = 0;
        long long colChipCost = 0;
        
        for (int i = 0; i < n; i++) {
            int rowIndex = rowCost[i].second;
            int colIndex = colCost[i].second;
            
            if (i % 2 == 0) {
                minCost += rowChipCost + a[rowIndex];
                rowChipCost += b[rowIndex];
            } else {
                minCost += colChipCost + b[colIndex];
                colChipCost += a[colIndex];
            }
        }
        
        cout << minCost << endl;
    }
    
    return 0;
}
