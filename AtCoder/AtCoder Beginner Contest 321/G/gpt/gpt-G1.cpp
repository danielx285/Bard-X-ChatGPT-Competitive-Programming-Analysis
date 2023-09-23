#include <iostream>
#include <vector>

const int MOD = 998244353;
const int MAX_N = 17;
const int MAX_M = 100005;

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> R(M);
    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        cin >> R[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = (1LL * dp[i - 1][j] * max(0, j - 1) + 1LL * dp[i - 1][j - 1] * max(0, N - j)) % MOD;
        }
    }

    int expected_s = 0;
    for (int j = 0; j <= N; j++) {
        int coeff = (j % 2 == 0) ? 1 : -1;
        expected_s = (expected_s + 1LL * coeff * dp[M][j] + MOD) % MOD;
    }

    int factorial = 1;
    for (int i = 2; i <= M; i++) {
        factorial = 1LL * factorial * i % MOD;
    }

    int answer = 1LL * expected_s * factorial % MOD;
    cout << answer << endl;

    return 0;
}
