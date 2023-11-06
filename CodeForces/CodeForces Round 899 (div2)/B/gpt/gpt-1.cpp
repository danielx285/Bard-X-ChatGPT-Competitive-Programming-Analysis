#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<set<int>> sets(n);
        set<int> all_elements;
        
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            
            for (int j = 0; j < k; j++) {
                int element;
                cin >> element;
                sets[i].insert(element);
                all_elements.insert(element);
            }
        }
        
        int max_attainable_size = 0;
        
        for (int i = 0; i < n; i++) {
            set<int> temp = all_elements;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    for (int element : sets[j]) {
                        temp.erase(element);
                    }
                }
            }
            
            max_attainable_size = max(max_attainable_size, int(temp.size()));
        }
        
        cout << max_attainable_size << endl;
    }
    
    return 0;
}
