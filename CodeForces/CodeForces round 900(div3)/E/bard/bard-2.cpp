#include <bits/stdc++.h>

using namespace std;

int f(vector<int>& a, int l, int r) {
  int res = a[l];
  for (int i = l + 1; i <= r; i++) {
    res &= a[i];
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    while (q--) {
      int l, k;
      cin >> l >> k;
      l--;

      int r = n - 1;
      while (l < r) {
        int mid = (l + r) / 2;
        if (f(a, l, mid) >= k) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }

      if (f(a, l, r) >= k) {
        cout << r + 1 << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }

  return 0;
}
