#include <iostream>
#include <set>

using namespace std;

typedef pair<int, int> Segment;

set<Segment> segments;

bool intersect(Segment a, Segment b) {
  return (a.first <= b.second && b.first <= a.second);
}

bool check_intersection() {
  for (auto it1 = segments.begin(); it1 != segments.end(); it1++) {
    for (auto it2 = it1; it2 != segments.end(); it2++) {
      if (it1 != it2 && intersect(*it1, *it2)) {
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
    char type;
    int l, r;
    cin >> type >> l >> r;

    if (type == '+') {
      segments.insert({l, r});
    } else if (type == '-') {
      segments.erase({l, r});
    }

    if (check_intersection()) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }

  return 0;
}
