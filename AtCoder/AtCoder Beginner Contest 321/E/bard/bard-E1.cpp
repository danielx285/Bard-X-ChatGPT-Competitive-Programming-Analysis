#include <bits/stdc++.h>

using namespace std;

#define N 1000000000000000000
#define MAX_K 1000000000

// A structure to represent a node in the tree.
struct Node {
  int parent;
  int depth;
  vector<int> children;
};

// A vector to store the nodes of the tree.
vector<Node> nodes(N);

// A function to recursively calculate the distance of all nodes from the root.
void calculateDistance(int node, int parent, int depth) {
  nodes[node].parent = parent;
  nodes[node].depth = depth;
  for (int child : nodes[node].children) {
    if (child != parent) {
      calculateDistance(child, node, depth + 1);
    }
  }
}

// A function to calculate the number of vertices whose distance from the given vertex is K.
int countVerticesAtDistanceK(int vertex, int K) {
  // If the distance is 0, then the answer is 1.
  if (K == 0) {
    return 1;
  }

  // If the distance is greater than the depth of the vertex, then the answer is 0.
  if (K > nodes[vertex].depth) {
    return 0;
  }

  // Otherwise, recursively calculate the answer by considering the children of the vertex.
  int count = 0;
  for (int child : nodes[vertex].children) {
    count += countVerticesAtDistanceK(child, K - 1);
  }
  return count;
}

// The main function.
int main() {
  // Read the number of test cases.
  int T;
  cin >> T;

  // For each test case, read the input and print the answer.
  for (int i = 0; i < T; i++) {
    // Read the input.
    long long N, X, K;
    cin >> N >> X >> K;

    // Initialize the nodes of the tree.
    for (int j = 0; j < N; j++) {
      nodes[j].parent = -1;
      nodes[j].depth = 0;
      nodes[j].children.clear();
    }

    // Build the tree.
    for (int j = 1; j < N; j++) {
      int parent = j / 2;
      nodes[j].parent = parent;
      nodes[parent].children.push_back(j);
    }

    // Calculate the distance of all nodes from the root.
    calculateDistance(X, -1, 0);

    // Calculate the number of vertices whose distance from the given vertex is K.
    int count = countVerticesAtDistanceK(X, K);

    // Print the answer.
    cout << count << endl;
  }

  return 0;
}
