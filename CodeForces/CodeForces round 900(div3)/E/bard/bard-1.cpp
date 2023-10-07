#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
const int MAXQ = 200000;

int a[MAXN];
int pref[MAXN];

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
      pref[i] = pref[i - 1] & a[i];
    }

    int q;
    cin >> q;
    while (q--) {
      int l, k;
      cin >> l >> k;
      l--;

      // Binary search to find the largest r such that f(l, r) >= k.
      int lft = l;
      int rgt = n - 1;
      int ans = -1;
      while (lft <= rgt) {
        int mid = (lft + rgt) / 2;
        if (pref[mid] & pref[l - 1] >= k) {
          ans = mid;
          lft = mid + 1;
        } else {
          rgt = mid - 1;
        }
      }

      cout << ans + 1 << endl;
    }
  }

  return 0;
}
