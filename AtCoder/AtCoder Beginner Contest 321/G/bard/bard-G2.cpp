#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> r(m), b(m);
  for (int i = 0; i < m; i++) {
    cin >> r[i] >> b[i];
  }

  // Calculate the number of connected components for each possible connection.
  vector<int> count(m! + 1, 0);
  for (int i = 0; i < m!; i++) {
    // Create a graph.
    vector<vector<int>> adj(n + 1);
    for (int j = 0; j < m; j++) {
      adj[r[j]].push_back(b[j]);
      adj[b[j]].push_back(r[j]);
    }

    // Count the number of connected components.
    vector<bool> visited(n + 1, false);
    int num_components = 0;
    for (int j = 1; j <= n; j++) {
      if (!visited[j]) {
        num_components++;
        dfs(adj, j, visited);
      }
    }

    count[i] = num_components;
  }

  // Calculate the expected value of the number of connected components.
  ll expected_value = 0;
  for (int i = 0; i < m!; i++) {
    expected_value += (count[i] * 1LL) * 1LL;
  }
  expected_value %= mod;

  // Find the modular inverse of the denominator.
  ll denominator = m!;
  ll numerator = 1;
  ll inverse = 1;
  while (denominator > 1) {
    ll remainder = denominator % numerator;
    if (remainder == 0) {
      inverse = numerator % mod;
      break;
    }
    denominator %= numerator;
    numerator = remainder;
  }

  // Calculate the final answer.
  ll answer = (expected_value * inverse) % mod;

  cout << answer << endl;

  return 0;
}

void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited) {
  visited[node] = true;
  for (int neighbor : adj[node]) {
    if (!visited[neighbor]) {
      dfs(adj, neighbor, visited);
    }
  }
}
