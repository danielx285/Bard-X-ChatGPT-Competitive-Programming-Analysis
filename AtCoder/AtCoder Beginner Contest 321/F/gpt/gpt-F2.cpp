#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MOD = 998244353;

int main() {
    int Q, K;
    cin >> Q >> K;

    vector<pair<char, int>> queries(Q);
    vector<int> count(5005, 0);
    vector<int> dp(K + 1, 0);

    for (int i = 0; i < Q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    vector<int> result;
    int current_sum = 0;

    for (int i = 0; i < Q; i++) {
        char op = queries[i].first;
        int x = queries[i].second;

        if (op == '+') {
            count[x]++;
            current_sum += x;
            current_sum %= K;

            for (int j = 0; j < K; j++) {
                dp[(j + x) % K] += dp[j];
                dp[(j + x) % K] %= MOD;
            }

            dp[x % K]++;

            if (current_sum == 0) {
                result.push_back(1);
            } else {
                result.push_back(0);
            }
        } else {
            count[x]--;
            current_sum += K - x;
            current_sum %= K;

            for (int j = 0; j < K; j++) {
                dp[(j + x) % K] -= dp[j];
                dp[(j + x) % K] = (dp[(j + x) % K] + MOD) % MOD;
            }

            dp[x % K]--;

            if (current_sum == 0) {
                result.push_back(1);
            } else {
                result.push_back(0);
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << result[i] << endl;
    }

    return 0;
}
