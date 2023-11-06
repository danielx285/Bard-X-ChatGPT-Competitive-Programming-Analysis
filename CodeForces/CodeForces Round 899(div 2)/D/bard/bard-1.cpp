#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
  int u;
  int v;
};

struct Node {
  int value;
  int subtree_size;
};

int n;
vector<vector<int>> adj;
vector<Edge> edges;
vector<Node> nodes;

void dfs(int root, int parent) {
  nodes[root].subtree_size = 1;
  for (int child : adj[root]) {
    if (child != parent) {
      dfs(child, root);
      nodes[root].subtree_size += nodes[child].subtree_size;
    }
  }
}

int min_cost(int root) {
  int min_cost = nodes[root].value;
  for (int child : adj[root]) {
    if (child != parent) {
      min_cost = min(min_cost, min_cost(child) + nodes[child].value);
    }
  }
  return min_cost;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    adj.resize(n + 1);
    nodes.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      edges.push_back({u, v});
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
      cin >> nodes[i].value;
    }

    dfs(1, 0);

    vector<int> min_costs(n + 1);
    for (int i = 1; i <= n; i++) {
      min_costs[i] = min_cost(i);
    }

    for (int i = 1; i <= n; i++) {
      cout << min_costs[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
