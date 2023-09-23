#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 998244353;
const int MAXN = 17;
const int MAXM = 100005;

long long dp[1 << MAXN][MAXN];
long long fact[MAXM];
long long invfact[MAXM];

long long modpow(long long base, long long exp) {
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

void init() {
    fact[0] = 1;
    for (int i = 1; i < MAXM; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invfact[MAXM - 1] = modpow(fact[MAXM - 1], MOD - 2);
    for (int i = MAXM - 2; i >= 0; i--) {
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (n < r || n < 0 || r < 0) {
        return 0;
    }
    return (fact[n] * invfact[r] % MOD) * invfact[n - r] % MOD;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> R(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> R[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    init();
    
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int mask = 0; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            if (dp[mask][i] == 0) continue;
            for (int j = 0; j < M; j++) {
                if ((mask >> (R[j] - 1)) & 1) {
                    dp[mask][i] = (dp[mask][i] * nCr(i + j, j)) % MOD;
                    dp[mask ^ (1 << (B[j] - 1))][B[j] - 1] = (dp[mask ^ (1 << (B[j] - 1))][B[j] - 1] + dp[mask][i]) % MOD;
                }
            }
        }
    }
    
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + dp[(1 << N) - 1][i] * (i + 1)) % MOD;
    }
    
    cout << ans << endl;

    return 0;
}
