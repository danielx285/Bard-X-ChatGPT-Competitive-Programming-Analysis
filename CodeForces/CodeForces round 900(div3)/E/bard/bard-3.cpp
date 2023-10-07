#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

int a[MAXN];
int dp[MAXN][20];

void precompute(int n) {
  for (int i = 0; i < n; i++) {
    dp[i][0] = a[i];
  }

  for (int j = 1; j < 20; j++) {
    for (int i = 0; i < n; i++) {
      if (i + (1 << j) - 1 >= n) {
        dp[i][j] = dp[i][j - 1];
      } else {
        dp[i][j] = dp[i][j - 1] & dp[i + (1 << (j - 1))][j - 1];
      }
    }
  }
}

int find_r(int l, int k) {
  int r = l;
  for (int i = 19; i >= 0; i--) {
    if (r + (1 << i) - 1 < n && dp[r][i] >= k) {
      r += (1 << i);
    }
  }

  if (dp[r][0] >= k) {
    return r;
  } else {
    return -1;
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    precompute(n);

    int q;
    cin >> q;

    while (q--) {
      int l, k;
      cin >> l >> k;

      l--;

      int r = find_r(l, k);
      cout << r << endl;
    }
  }

  return 0;
}
