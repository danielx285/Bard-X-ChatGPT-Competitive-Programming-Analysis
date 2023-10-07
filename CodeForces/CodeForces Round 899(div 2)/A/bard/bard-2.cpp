#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> a) {
  int n = a.size();
  sort(a.begin(), a.end());

  int min_bn = a[n - 1] + 1;
  for (int i = 0; i < n - 1; i++) {
    min_bn = min(min_bn, a[i] + 1);
  }

  return min_bn;
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

    int min_bn = solve(a);
    cout << min_bn << endl;
  }

  return 0;
}
