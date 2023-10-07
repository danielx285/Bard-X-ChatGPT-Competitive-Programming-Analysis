#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<set<int>> sets(n);
    for (int i = 0; i < n; i++) {
      int ki;
      cin >> ki;
      for (int j = 0; j < ki; j++) {
        int sij;
        cin >> sij;
        sets[i].insert(sij);
      }
    }

    // Find the union of all sets.
    set<int> all_elements;
    for (int i = 0; i < n; i++) {
      for (auto element : sets[i]) {
        all_elements.insert(element);
      }
    }

    // Find the maximum number of elements in an attainable S such that S≠S1∪S2∪…∪Sn.
    int max_size = 0;
    for (int i = 1; i < (1 << n); i++) {
      // Create a set of elements in the current subset.
      set<int> current_set;
      for (int j = 0; j < n; j++) {
        if ((i >> j) & 1) {
          current_set.insert(sets[j].begin(), sets[j].end());
        }
      }

      // Check if the current subset is different from the union of all sets.
      if (current_set != all_elements) {
        max_size = max(max_size, current_set.size());
      }
    }

    cout << max_size << endl;
  }
  return 0;
}
