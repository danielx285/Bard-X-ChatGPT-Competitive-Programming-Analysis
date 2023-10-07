#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353;

ll f(vector<int>& a, int l, int r) {
  ll x = 0;
  for (int i = l; i <= r; i++) {
    x ^= a[i];
  }
  return x;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll ans = 0;
  for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
      ans += (r - l + 1) * f(a, l, r);
      ans %= mod;
    }
  }

  cout << ans << endl;

  return 0;
}
