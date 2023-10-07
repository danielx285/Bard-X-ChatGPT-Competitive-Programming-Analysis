#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    long long answer = 0;
    long long prefixXOR = 0;
    
    for (int i = 0; i < n; ++i) {
        prefixXOR ^= a[i];
        long long currentSum = 0;
        long long multiplier = 1;
        
        for (int j = i; j < n; ++j) {
            currentSum = (currentSum + (prefixXOR * multiplier) % MOD) % MOD;
            answer = (answer + currentSum) % MOD;
            multiplier++;
        }
    }
    
    std::cout << answer << std::endl;
    
    return 0;
}
