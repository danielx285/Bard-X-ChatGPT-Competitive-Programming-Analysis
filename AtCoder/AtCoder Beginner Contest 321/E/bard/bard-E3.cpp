#include <iostream>
#include <vector>

using namespace std;

// This function calculates the distance between two vertices in a tree.
int distance(vector<vector<int>>& tree, int u, int v) {
  // Base case.
  if (u == v) {
    return 0;
  }

  // Recursive case.
  int min_distance = INT_MAX;
  for (int child : tree[u]) {
    int distance_from_child = distance(tree, child, v);
    if (distance_from_child != -1) {
      min_distance = min(min_distance, distance_from_child + 1);
    }
  }

  // If there is no path between u and v, return -1.
  if (min_distance == INT_MAX) {
    return -1;
  } else {
    return min_distance;
  }
}

// This function counts the number of vertices whose distance from vertex X is K.
int count_vertices_at_distance_K(vector<vector<int>>& tree, int X, int K) {
  // Base case.
  if (K == 0) {
    return 1;
  }

  // Recursive case.
  int count = 0;
  for (int child : tree[X]) {
    int distance_from_child = distance(tree, child, X);
    if (distance_from_child != -1 && distance_from_child + 1 == K) {
      count += count_vertices_at_distance_K(tree, child, K - 1);
    }
  }

  return count;
}

int main() {
  // Read the number of test cases.
  int T;
  cin >> T;

  // Solve each test case.
  for (int i = 0; i < T; i++) {
    // Read the input for the current test case.
    int N, X, K;
    cin >> N >> X >> K;

    // Construct the tree.
    vector<vector<int>> tree(N + 1);
    for (int j = 2; j <= N; j++) {
      tree[j].push_back(j / 2);
    }

    // Calculate the number of vertices whose distance from vertex X is K.
    int count = count_vertices_at_distance_K(tree, X, K);

    // Print the answer.
    cout << count << endl;
  }

  return 0;
}
