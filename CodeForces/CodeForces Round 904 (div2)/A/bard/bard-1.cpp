#include <iostream>
#include <algorithm>

using namespace std;

bool isKBeautiful(int n, int k) {
  int digit_sum = 0;
  while (n > 0) {
    digit_sum += n % 10;
    n /= 10;
  }
  return digit_sum % k == 0;
}

int findSmallestKBeautiful(int x, int k) {
  int y = x;
  while (!isKBeautiful(y, k)) {
    y++;
  }
  return y;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, k;
    cin >> x >> k;
    cout << findSmallestKBeautiful(x, k) << endl;
  }
  return 0;
}
