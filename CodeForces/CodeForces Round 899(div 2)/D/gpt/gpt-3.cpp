#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int a[MAXN];
long long ans[MAXN];

void dfs(int u, int parent) {
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        a[u] ^= a[v];
    }
    ans[u] = a[u];
    for (int v : adj[u]) {
        if (v == parent) continue;
        ans[u] += ans[v];
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
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
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
