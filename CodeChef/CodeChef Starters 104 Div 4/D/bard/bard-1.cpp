#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}

int minSumAfterKOps(int x, int y, int k) {
  // If K is even, then Alice and Bob can reduce the sum to the LCM of X and Y.
  if (k % 2 == 0) {
    return lcm(x, y);
  }

  // If K is odd, then Alice and Bob can reduce the sum to the GCD of X and Y.
  else {
    return gcd(x, y);
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int x, y, k;
    cin >> x >> y >> k;

    cout << minSumAfterKOps(x, y, k) << endl;
  }

  return 0;
}
