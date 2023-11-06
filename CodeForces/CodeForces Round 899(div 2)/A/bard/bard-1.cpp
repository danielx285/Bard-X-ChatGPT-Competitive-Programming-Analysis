#include <iostream>
#include <algorithm>

using namespace std;

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

    int max_value = a[n - 1];
    int min_value = 0;

    for (int i = 0; i < n - 1; i++) {
      if (a[i] + 1 < a[i + 1]) {
        min_value = a[i] + 1;
        break;
      }
    }

    if (min_value == 0) {
      min_value = max_value + 1;
    }

    cout << min_value << endl;
  }

  return 0;
}
