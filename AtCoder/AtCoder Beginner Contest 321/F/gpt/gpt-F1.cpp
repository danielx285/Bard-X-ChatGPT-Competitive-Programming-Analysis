#include <iostream>
#include <vector>
#include <map>
#define MOD 998244353
using namespace std;

int main() {
    int Q, K;
    cin >> Q >> K;
    vector<long long> ways(K + 1);
    ways[0] = 1;
    map<int, int> counts;
    int sum = 0;

    for (int i = 0; i < Q; i++) {
        char op;
        int x;
        cin >> op >> x;

        if (op == '+') {
            counts[x]++;
            sum += x;
        } else {
            counts[x]--;
            sum -= x;
        }

        for (int j = K; j >= 0; j--) {
            long long cnt = 0;
            for (auto &pair : counts) {
                int num = pair.first;
                int freq = pair.second;
                if (j >= num) {
                    cnt += (ways[j - num] * freq) % MOD;
                    cnt %= MOD;
                }
            }
            ways[j] = cnt;
        }

        cout << ways[K] << endl;
    }

    return 0;
}
