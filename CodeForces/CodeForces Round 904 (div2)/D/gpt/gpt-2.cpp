#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

int t, n;
int a[MAXN];
vector<int> divisors[MAXN];

void precompute_divisors() {
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            divisors[j].push_back(i);
        }
    }
}

int count_good_pairs() {
    precompute_divisors();
    int good_pairs = 0;
    
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<int> divisible(n, 0);
        for (int i = 0; i < n; i++) {
            for (int d : divisors[a[i]]) {
                divisible[i] += d;
            }
        }
        
        map<int, int> counts;
        long long total_good_pairs = 0;
        long long total_singles = 0;
        
        for (int i = 0; i < n; i++) {
            total_good_pairs += counts[divisible[i]];
            total_singles += n - i - 1;
            counts[divisible[i]]++;
        }
        
        long long total_pairs = (long long)n * (n - 1) / 2;
        long long bad_pairs = total_pairs - total_singles - total_good_pairs;
        
        cout << bad_pairs << "\n";
    }
    
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    count_good_pairs();
    
    return 0;
}
