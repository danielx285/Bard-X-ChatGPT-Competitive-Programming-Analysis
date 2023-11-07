#include <iostream>
#include <set>

using namespace std;

struct Segment {
  int l, r;
};

bool operator<(const Segment& s1, const Segment& s2) {
  return s1.l < s2.l;
}

int main() {
  int q;
  cin >> q;

  multiset<Segment> segments;

  while (q--) {
    char op;
    int l, r;
    cin >> op >> l >> r;

    if (op == '+') {
      segments.insert({l, r});
    } else if (op == '-') {
      segments.erase({l, r});
    }

    // Check if there exists a pair of segments that do not intersect.
    bool intersect = false;
    for (auto it = segments.begin(); it != segments.end(); ++it) {
      for (auto jt = next(it); jt != segments.end(); ++jt) {
        if (it->r < jt->l || jt->r < it->l) {
          intersect = true;
          break;
        }
      }
      if (intersect) {
        break;
      }
    }

    // Print the answer.
    if (intersect) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
