#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // Calculate the prefix XOR array.
  vector<int> p(n + 1);
  p[0] = 0;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] ^ a[i - 1];
  }

  // Calculate the answer.
  long long ans = 0;
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      int f = p[r] ^ p[l - 1];
      ans += (r - l + 1) * f;
      ans %= MOD;
    }
  }

  cout << ans << endl;

  return 0;
}
