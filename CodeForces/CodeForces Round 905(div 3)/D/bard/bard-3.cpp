#include <bits/stdc++.h>

using namespace std;

struct Segment {
  int l, r;
};

multiset<Segment> segments;

bool intersect(Segment a, Segment b) {
  return a.l <= b.r && a.r >= b.l;
}

bool checkPairwiseIntersection() {
  for (auto it = segments.begin(); it != segments.end(); it++) {
    for (auto jt = next(it); jt != segments.end(); jt++) {
      if (!intersect(*it, *jt)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int q;
  cin >> q;

  while (q--) {
    char op;
    int l, r;
    cin >> op >> l >> r;

    if (op == '+') {
      segments.insert({l, r});
    } else {
      segments.erase({l, r});
    }

    cout << (checkPairwiseIntersection() ? "YES" : "NO") << endl;
  }

  return 0;
}
