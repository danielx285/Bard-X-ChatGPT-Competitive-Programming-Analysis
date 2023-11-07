#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());

    bool possible = true;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] + a[i + 1] != a[i + 1] + a[i + 2]) {
        possible = false;
        break;
      }
    }

    if (possible) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
