#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 50;
const int MAX_K = 50;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<set<int>> sets(n);
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;

      for (int j = 0; j < k; j++) {
        int element;
        cin >> element;

        sets[i].insert(element);
      }
    }

    // Find the maximum size of an attainable set such that S≠S1∪S2∪…∪Sn.

    int max_size = 0;
    for (int i = 1; i < (1 << n); i++) {
      // Create a new set to store the elements of the attainable set.

      set<int> subset;

      // Iterate over the sets and add the elements to the subset if the corresponding bit in i is set.

      for (int j = 0; j < n; j++) {
        if ((i >> j) & 1) {
          for (auto it = sets[j].begin(); it != sets[j].end(); it++) {
            subset.insert(*it);
          }
        }
      }

      // If the subset is not equal to the union of all sets, then it is an attainable set.

      if (subset != sets[0]) {
        max_size = max(max_size, subset.size());
      }
    }

    // Print the maximum size of the attainable set.

    cout << max_size << endl;
  }

  return 0;
}
