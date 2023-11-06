#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    vector<int> min_ops(n + 1, -1);
    min_ops[0] = 0;

    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == '1') {
        min_ops[i] = min_ops[i - 1];
      } else {
        if (i >= 2 && s[i - 2] == '1') {
          min_ops[i] = min_ops[i - 2] + 1;
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      if (min_ops[n - i] == -1 || (n - i) % i != 0) {
        cout << -1 << " ";
      } else {
        cout << min_ops[n - i] << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
