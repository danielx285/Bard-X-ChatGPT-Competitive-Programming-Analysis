#include <iostream>
#include <vector>

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
  vector<int> pref(n + 1);
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] ^ a[i - 1];
  }

  // Calculate the answer.
  long long ans = 0;
  for (int l = 1; l <= n; l++) {
    long long sum = 0;
    for (int r = l; r <= n; r++) {
      int xor_value = pref[r] ^ pref[l - 1];
      sum = (sum + xor_value * (r - l + 1)) % MOD;
    }
    ans = (ans + sum) % MOD;
  }

  cout << ans << endl;

  return 0;
}
