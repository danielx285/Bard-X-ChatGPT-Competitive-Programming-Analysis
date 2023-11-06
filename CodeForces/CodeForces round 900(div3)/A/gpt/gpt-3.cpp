#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool hasMostCommonSubsegment(vector<int>& a, int k) {
    unordered_map<int, int> freq;
    int maxFreq = 0;
    int n = a.size();

    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
        maxFreq = max(maxFreq, freq[a[i]]);
    }

    return maxFreq >= freq[k];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (hasMostCommonSubsegment(a, k)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
