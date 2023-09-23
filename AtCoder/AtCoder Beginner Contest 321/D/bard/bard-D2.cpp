#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, p;
  cin >> n >> m >> p;

  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  long long total_price = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      long long s = a[i] + b[j];
      total_price += min(s, p);
    }
  }

  cout << total_price << endl;

  return 0;
}
