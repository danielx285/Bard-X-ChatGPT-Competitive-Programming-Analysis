#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int n;
ll a[MAXN];
vector<int> adj[MAXN];

ll dp[MAXN][2]; // dp[i][j] = minimum cost to make all ai equal, if vertex i is chosen as the root
                   // of the tree and the parity of the sum of ai in the subtree of i is j

void dfs(int u, int p) {
  dp[u][0] = dp[u][1] = LLONG_MAX;

  ll sum = a[u];
  for (auto v : adj[u]) {
    if (v != p) {
      dfs(v, u);
      sum += a[v];

      ll cost = min(dp[v][0] + (sum % 2 == 0), dp[v][1] + (sum % 2 == 1));
      dp[u][0] = min(dp[u][0], cost);
      dp[u][1] = min(dp[u][1], cost + (1LL << (20 - __builtin_clz(sum))));
    }
  }

  if (sum % 2 == 0) {
    dp[u][0] = min(dp[u][0], dp[u][1] + (1LL << (20 - __builtin_clz(sum))));
  } else {
    dp[u][1] = min(dp[u][1], dp[u][0] + (1LL << (20 - __builtin_clz(sum))));
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
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

    for (int i = 1; i <= n; i++) {
      dfs(i, -1);
    }

    for (int i = 1; i <= n; i++) {
      cout << dp[i][0] << " ";
    }

    cout << endl;
  }

  return 0;
}
