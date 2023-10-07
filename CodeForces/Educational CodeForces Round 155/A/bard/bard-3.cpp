#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> s(n);
    vector<int> e(n);

    for (int i = 0; i < n; i++) {
      cin >> s[i] >> e[i];
    }

    // Find the maximum strength of an athlete who is not Polycarp.
    int max_strength = 0;
    for (int i = 1; i < n; i++) {
      max_strength = max(max_strength, s[i]);
    }

    // If Polycarp's strength is greater than the maximum strength of any other
    // athlete, then Polycarp can win the competition by lifting the barbell
    // once.
    if (s[0] > max_strength) {
      cout << 1 << endl;
      continue;
    }

    // Otherwise, check if Polycarp can win the competition by lifting the barbell
    // multiple times.
    int w = 1;
    while (w <= max_strength) {
      int max_lifts = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] >= w) {
          max_lifts = max(max_lifts, e[i]);
        }
      }

      if (max_lifts == e[0]) {
        // Polycarp can win the competition by lifting the barbell w times.
        cout << w << endl;
        break;
      }

      w++;
    }

    // If Polycarp cannot win the competition by lifting the barbell any number
    // of times, then print -1.
    if (w > max_strength) {
      cout << -1 << endl;
    }
  }

  return 0;
}
