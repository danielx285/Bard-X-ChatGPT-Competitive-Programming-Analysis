#include <iostream>
#include <vector>
#include <algorithm>

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

    sort(segments.begin(), segments.end());

    vector<int> a(m, 0);
    int max_cost = 0;

    for (int i = 0; i < (1 << n); i++) {
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          for (int k = segments[j].first; k <= segments[j].second; k++) {
            a[k]++;
          }
        }
      }

      int max_value = *max_element(a.begin(), a.end());
      int min_value = *min_element(a.begin(), a.end());
      int cost = max_value - min_value;

      max_cost = max(max_cost, cost);

      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          for (int k = segments[j].first; k <= segments[j].second; k++) {
            a[k]--;
          }
        }
      }
    }

    cout << max_cost << endl;
  }

  return 0;
}
