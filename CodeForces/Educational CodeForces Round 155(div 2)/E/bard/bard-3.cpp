#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int MAX_N = 100;

struct Edge {
  int u, v;
  int color;
};

vector<Edge> edges;
vector<vector<int>> adj_list;
vector<int> edge_colors;

void dfs(int u, int parent, int color) {
  edge_colors[u] = color;
  for (int v : adj_list[u]) {
    if (v != parent) {
      dfs(v, u, color + 1);
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> parents(n);
  for (int i = 1; i < n; i++) {
    cin >> parents[i];
    parents[i]--;
  }

  adj_list.resize(n);
  for (int i = 1; i < n; i++) {
    adj_list[i].push_back(parents[i]);
    adj_list[parents[i]].push_back(i);
  }

  edge_colors.resize(n, 0);

  // Color the edges of the tree.
  int k = 1;
  for (int i = 1; i < n; i++) {
    if (edge_colors[i] == 0) {
      dfs(i, parents[i], k);
      k++;
    }
  }

  cout << k - 1 << endl;
  for (int i = 1; i < n; i++) {
    cout << edge_colors[i] << " ";
  }
  cout << endl;
  flush(stdout);

  // Play the game.
  int current_vertex = 0;
  while (true) {
    int code;
    cin >> code;
    if (code == 1) {
      // We won!
      break;
    } else if (code == -1) {
      // We lost.
      break;
    } else if (code == 0) {
      // We need to make a move.
      vector<int> edge_counts(k);
      for (int i = 0; i < k; i++) {
        cin >> edge_counts[i];
      }

      // Choose a color to move along.
      int chosen_color = -1;
      for (int i = 0; i < k; i++) {
        if (edge_counts[i] > 0) {
          chosen_color = i;
          break;
        }
      }

      cout << chosen_color + 1 << endl;
      flush(stdout);

      current_vertex = adj_list[current_vertex][edge_colors[current_vertex] - chosen_color];
    }
  }

  return 0;
}
