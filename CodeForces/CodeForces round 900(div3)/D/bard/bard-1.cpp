#include <iostream>
#include <algorithm>

using namespace std;

void reverse_substring(string& s, int a, int b) {
  reverse(s.begin() + a, s.begin() + b + 1);
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> l(k), r(k);
    for (int i = 0; i < k; i++) {
      cin >> l[i] >> r[i];
    }

    int q;
    cin >> q;

    vector<int> x(q);
    for (int i = 0; i < q; i++) {
      cin >> x[i];
    }

    for (int i = 0; i < q; i++) {
      int idx = 0;
      while (l[idx] > x[i] || r[idx] < x[i]) {
        idx++;
      }

      int a = min(x[i], r[idx] + l[idx] - x[i]);
      int b = max(x[i], r[idx] + l[idx] - x[i]);

      reverse_substring(s, a, b);
    }

    cout << s << endl;
  }

  return 0;
}
