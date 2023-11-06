#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

#define INF 1e9

// Tree representation
struct Node {
  int id;
  vi children;
  int subtree_size;
};

vector<Node> nodes;

// Calculates the size of the subtree rooted at v
void dfs_subtree_size(int v) {
  nodes[v].subtree_size = 1;
  for (int child : nodes[v].children) {
    dfs_subtree_size(child);
    nodes[v].subtree_size += nodes[child].subtree_size;
  }
}

// Calculates the minimum cost to make all values in a equal,
// if vertex v is chosen as the root of the tree
int min_cost(int v) {
  // Priority queue to store the vertices in decreasing order of subtree size
  priority_queue<ii, vector<ii>, greater<ii>> pq;

  // Initialize the priority queue
  for (int child : nodes[v].children) {
    pq.push({nodes[child].subtree_size, child});
  }

  // Minimum cost
  int min_cost = 0;

  // While the priority queue is not empty
  while (!pq.empty()) {
    ii vertex = pq.top();
    pq.pop();

    // Cost of the current spell
    int cost = vertex.first * vertex.second;

    // Update the minimum cost
    min_cost = min(min_cost, cost);

    // Add the children of the current vertex to the priority queue
    for (int child : nodes[vertex.second].children) {
      pq.push({nodes[child].subtree_size, child});
    }
  }

  return min_cost;
}

// Solves the tree equalization problem
void solve_tree_equalization() {
  // Read the input
  int n;
  cin >> n;

  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // Initialize the tree
  nodes.resize(n);
  for (int i = 0; i < n; i++) {
    nodes[i].id = i;
    nodes[i].children = vi();
  }

  // Read the edges
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    nodes[u].children.push_back(v);
    nodes[v].children.push_back(u);
  }

  // Calculate the size of each subtree
  for (int i = 0; i < n; i++) {
    dfs_subtree_size(i);
  }

  // Calculate the minimum cost for each vertex as the root
  vi min_cost(n);
  for (int i = 0; i < n; i++) {
    min_cost[i] = min_cost(i);
  }

  // Print the output
  for (int i = 0; i < n; i++) {
    cout << min_cost[i] << " ";
  }
  cout << endl;
}

int main() {
  // Read the number of test cases
  int t;
  cin >> t;

  // Solve each test case
  while (t--) {
    solve_tree_equalization();
  }

  return 0;
}
