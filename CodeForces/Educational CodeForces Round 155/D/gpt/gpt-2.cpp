#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long result = 0;
    long long xor_sum = 0;

    for (int i = 0; i < n; ++i) {
        xor_sum ^= a[i];
        long long contribution = 0;

        for (int j = i; j < n; ++j) {
            xor_sum ^= a[j];
            contribution += xor_sum * (j - i + 1);
            contribution %= MOD;
        }

        result += contribution;
        result %= MOD;
    }

    std::cout << result << std::endl;

    return 0;
}
