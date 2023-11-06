#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; i++) {
      cin >> segments[i].first >> segments[i].second;
    }

    // Create a vector to store the maximum cost of each subset of segments.
    vector<int> max_cost(1 << n);

    // Initialize the maximum cost of each subset to 0.
    for (int i = 0; i < (1 << n); i++) {
      max_cost[i] = 0;
    }

    // Iterate over all subsets of segments.
    for (int i = 0; i < (1 << n); i++) {
      // Create an array to store the values of the array a.
      vector<int> a(m);

      // For each segment in the current subset, increase the values of the
      // corresponding elements in the array a.
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          for (int k = segments[j].first; k <= segments[j].second; k++) {
            a[k]++;
          }
        }
      }

      // Compute the maximum and minimum values of the array a.
      int max_value = *max_element(a.begin(), a.end());
      int min_value = *min_element(a.begin(), a.end());

      // Compute the cost of the current subset of segments.
      int cost = max_value - min_value;

      // Update the maximum cost of the current subset of segments, if
      // necessary.
      max_cost[i] = max(max_cost[i], cost);
    }

    // Output the maximum cost among all subsets of segments.
    cout << *max_element(max_cost.begin(), max_cost.end()) << endl;
  }

  return 0;
}
