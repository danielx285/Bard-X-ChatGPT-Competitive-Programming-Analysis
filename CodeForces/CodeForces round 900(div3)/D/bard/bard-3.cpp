#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Segment {
  int l, r;
};

string reverse(string s, int a, int b) {
  string reversed = s.substr(a, b - a + 1);
  reverse(reversed.begin(), reversed.end());
  s.replace(a, b - a + 1, reversed);
  return s;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<Segment> segments(k);
    for (int i = 0; i < k; i++) {
      cin >> segments[i].l >> segments[i].r;
    }

    int q;
    cin >> q;

    vector<int> modifications(q);
    for (int i = 0; i < q; i++) {
      cin >> modifications[i];
    }

    for (int i = 0; i < q; i++) {
      int x = modifications[i];
      for (int j = 0; j < k; j++) {
        if (segments[j].l <= x && x <= segments[j].r) {
          s = reverse(s, min(x, segments[j].r + segments[j].l - x),
                      max(x, segments[j].r + segments[j].l - x));
          break;
        }
      }
    }

    cout << s << endl;
  }

  return 0;
}
