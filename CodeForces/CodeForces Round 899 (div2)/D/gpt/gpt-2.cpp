#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n;
vector<int> a(MAXN);
vector<vector<int>> adj(MAXN);
vector<int> answer(MAXN);

vector<int> prefix_xor(MAXN);
vector<int> total_xor(MAXN);

void dfs(int u, int p) {
    prefix_xor[u] = a[u];

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        prefix_xor[u] ^= prefix_xor[v];
    }

    total_xor[u] = prefix_xor[u];

    for (int v : adj[u]) {
        if (v == p) continue;
        total_xor[u] ^= total_xor[v];
    }

    answer[u] = total_xor[u];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0);

        for (int i = 1; i <= n; i++) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
