#include <iostream>
#include <vector>

using namespace std;

// Represents a tree.
struct Tree {
  int n; // Number of vertices in the tree.
  vector<vector<int>> adj; // Adjacency list of the tree.
};

// Reads a tree from the input stream.
Tree readTree() {
  Tree tree;
  cin >> tree.n;
  tree.adj.resize(tree.n);
  for (int i = 2; i <= tree.n; i++) {
    int parent;
    cin >> parent;
    tree.adj[parent].push_back(i);
    tree.adj[i].push_back(parent);
  }
  return tree;
}

// Colors the edges of a tree using the minimum possible number of colors such that
// the player can win the game.
vector<int> colorTree(const Tree& tree) {
  // Compute the number of edges incident to each vertex.
  vector<int> deg(tree.n);
  for (int i = 1; i < tree.n; i++) {
    deg[i] = tree.adj[i].size();
  }

  // Color the edges greedily.
  vector<int> color(tree.n - 1);
  int num_colors = 0;
  for (int i = 1; i < tree.n; i++) {
    if (deg[i] == 1) {
      // This vertex is a leaf, so we can color it with any color we want.
      color[i - 1] = num_colors++;
    } else {
      // This vertex is not a leaf, so we have to choose a color that is not
      // already used by any of its neighbors.
      vector<bool> used(num_colors, false);
      for (int neighbor : tree.adj[i]) {
        used[color[neighbor - 1]] = true;
      }
      for (int j = 0; j < num_colors; j++) {
        if (!used[j]) {
          color[i - 1] = j;
          break;
        }
      }
      if (color[i - 1] == num_colors) {
        num_colors++;
      }
    }
  }

  return color;
}

// Plays the game on a tree with the given coloring.
void playGame(const Tree& tree, const vector<int>& color) {
  // Flush the output before starting the game.
  fflush(stdout);

  // The current vertex.
  int current_vertex = 1;

  // While the chip is not at the root, make a move.
  while (current_vertex != 1) {
    // Print the number of edges of each color incident to the current vertex.
    cout << 0 << endl;
    for (int i = 0; i < color.size(); i++) {
      cout << count(tree.adj[current_vertex].begin(), tree.adj[current_vertex].end(), i + 2) << " ";
    }
    cout << endl;

    // Flush the output before reading the jury's response.
    fflush(stdout);

    // Read the jury's response.
    int response;
    cin >> response;

    if (response == 1) {
      // The chip has reached the root and we won.
      return;
    } else if (response == -1) {
      // We lost.
      exit(0);
    } else if (response == 0) {
      // The jury has given us information about the current vertex.
      vector<int> num_edges(color.size());
      for (int i = 0; i < color.size(); i++) {
        cin >> num_edges[i];
      }

      // Choose
