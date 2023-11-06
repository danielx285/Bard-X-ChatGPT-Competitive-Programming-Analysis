#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> s(n), e(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i] >> e[i];
    }

    // Sort the athletes by their strength in decreasing order.
    sort(s.begin(), s.end(), greater<>());

    // Find the weight of the barbell that Polycarp can lift the most amount of times.
    int w = s[0];
    for (int i = 1; i < n; i++) {
      if (s[i] > w) {
        w = s[i];
      }
    }

    // Check if Polycarp can lift the barbell at least once.
    if (w > s[0]) {
      cout << -1 << endl;
      continue;
    }

    // Check if any of the other athletes can lift the barbell the same number of times as Polycarp.
    bool has_winner = true;
    for (int i = 1; i < n; i++) {
      if (s[i] >= w && e[i] > e[0]) {
        has_winner = false;
        break;
      }
    }

    if (has_winner) {
      cout << w << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
