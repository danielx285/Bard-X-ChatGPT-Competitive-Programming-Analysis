#include <algorithm>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}

int minimumSum(int x, int y, int k) {
  // If k is odd, then the final sum will be the gcd of x and y.
  if (k % 2 == 1) {
    return gcd(x, y);
  }

  // If k is even, then the final sum will be the lcm of x and y.
  return lcm(x, y);
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int x, y, k;
    cin >> x >> y >> k;

    cout << minimumSum(x, y, k) << endl;
  }

  return 0;
}
