#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int a[n];
    a[0] = 6;
    a[1] = 8;
    for (int i = 2; i < n; i++) {
      a[i] = a[i - 1] + a[i - 2] + 1;
    }

    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
