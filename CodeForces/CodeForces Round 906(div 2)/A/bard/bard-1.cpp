#include <bits/stdc++.h>

using namespace std;

bool isGood(vector<int> &a) {
  int n = a.size();
  int sum = a[0] + a[1];
  for (int i = 1; i < n - 1; i++) {
    if (a[i] + a[i + 1] != sum) {
      return false;
    }
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());

    bool canMakeGood = isGood(a);
    if (canMakeGood) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
