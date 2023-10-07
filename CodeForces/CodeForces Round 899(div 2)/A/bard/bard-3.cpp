#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a, a + n);

    int max_b = a[n - 1] + 1;
    for (int i = 0; i < n; i++) {
      if (i == 0 || a[i] != a[i - 1]) {
        max_b = min(max_b, a[i] - 1);
      }
    }

    cout << max_b << endl;
  }

  return 0;
}
