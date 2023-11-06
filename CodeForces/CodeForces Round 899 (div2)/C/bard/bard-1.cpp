#include <iostream>
#include <vector>

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

    int score = 0;
    int i = 0;
    while (i < n) {
      if (a[i] > 0) {
        if (i % 2 == 0) {
          score += a[i];
          i++;
        } else {
          i++;
        }
      } else {
        i++;
      }
    }

    cout << score << endl;
  }
  return 0;
}
