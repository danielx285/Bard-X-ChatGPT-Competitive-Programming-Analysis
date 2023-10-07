#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

vector<int> adj[MAXN];
int color[MAXN];

void dfs(int u, int p) {
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
}

void print_coloring(int k) {
  cout << k << endl;
  for (int i = 2; i <= MAXN - 1; i++) {
    cout << color[i] << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= n - 1; i++) {
    int p;
    cin >> p;
    adj[p].push_back(i);
    adj[i].push_back(p);
  }

  // Color the edges using a greedy algorithm.
  int k = 1;
  for (int i = 2; i <= n - 1; i++) {
    if (color[i] == 0) {
      color[i] = k;
      k++;
    }
  }

  print_coloring(k - 1);

  // The game begins.
  while (true) {
    int status;
    cin >> status;
    if (status == 1) {
      // We won!
      break;
    } else if (status == -1) {
      // We lost.
      break;
    }

    // Get the number of edges of each color incident to the current vertex.
    vector<int> edges(k);
    for (int i = 0; i < k; i++) {
      cin >> edges[i];
    }

    // Choose a color to move along.
    int chosen_color = -1;
    for (int i = 0; i < k; i++) {
      if (edges[i] > 0) {
        chosen_color = i;
        break;
      }
    }

    // Print our choice.
    cout << chosen_color << endl;
  }

  return 0;
}
