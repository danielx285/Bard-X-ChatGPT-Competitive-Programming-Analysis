#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int Q, K;
    std::cin >> Q >> K;

    std::vector<int> cnt(5001, 0);
    std::vector<long long> dp(5001, 0);
    cnt[0] = 1;
    dp[0] = 1;
    long long sum = 0;

    for (int i = 0; i < Q; ++i) {
        char op;
        int x;
        std::cin >> op >> x;

        if (op == '+') {
            for (int j = K; j >= x; --j) {
                dp[j] += dp[j - x];
                dp[j] %= MOD;
            }
            cnt[x]++;
        } else {
            for (int j = K; j >= x; --j) {
                dp[j] -= dp[j - x] * cnt[x] % MOD;
                dp[j] = (dp[j] % MOD + MOD) % MOD;
            }
            cnt[x]--;
        }

        sum += dp[K];
        sum %= MOD;

        std::cout << sum << std::endl;
    }

    return 0;
}
