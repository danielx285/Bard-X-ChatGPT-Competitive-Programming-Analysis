#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 998244353;

long long mod_pow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> R(M);
    vector<int> B(M);
    for (int i = 0; i < M; ++i) {
        cin >> R[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    vector<vector<long long>> dp(M + 1, vector<long long>(1 << N, 0));

    dp[0][0] = 1;

    for (int i = 0; i < M; ++i) {
        for (int mask = 0; mask < (1 << N); ++mask) {
            dp[i + 1][mask] += dp[i][mask];
            dp[i + 1][mask | (1 << (R[i] - 1))] += dp[i][mask];
            dp[i + 1][mask | (1 << (B[i] - 1))] += dp[i][mask];
            dp[i + 1][mask] %= MOD;
            dp[i + 1][mask | (1 << (R[i] - 1))] %= MOD;
            dp[i + 1][mask | (1 << (B[i] - 1))] %= MOD;
        }
    }

    long long expected_s = 0;

    for (int mask = 0; mask < (1 << N); ++mask) {
        int components = 0;
        for (int i = 1; i <= N; ++i) {
            if (mask & (1 << (i - 1))) {
                components++;
            }
        }
        expected_s += components * dp[M][mask];
        expected_s %= MOD;
    }

    long long inv_fact_M = 1;
    for (int i = 1; i <= M; ++i) {
        inv_fact_M = (inv_fact_M * mod_pow(i, MOD - 2)) % MOD;
    }

    expected_s = (expected_s * mod_pow(inv_fact_M, MOD - 2)) % MOD;

    cout << expected_s << endl;

    return 0;
}
