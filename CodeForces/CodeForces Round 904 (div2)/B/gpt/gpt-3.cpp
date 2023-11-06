#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        vector<int> ans(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                for (int j = i; j >= 0; j--) {
                    if (s[j] == '1') {
                        int cnt = i - j;
                        if (ans[cnt] == -1 || ans[cnt] > i) {
                            ans[cnt] = i;
                        }
                    }
                }
            }
        }
        
        int cur = -1;
        for (int i = 0; i < n; i++) {
            if (ans[i] == -1) {
                break;
            }
            cur = max(cur, ans[i]);
            cout << cur << " ";
        }
        cout << "\n";
    }
    return 0;
}
