#include <iostream>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

int minSum(int x, int y, int k) {
  int sum = x + y;
  while (k > 0) {
    if (x > y) {
      x = gcd(x, y);
    } else {
      y = gcd(x, y);
    }
    sum = x + y;
    k--;
  }
  return sum;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y, k;
    cin >> x >> y >> k;
    cout << minSum(x, y, k) << endl;
  }
  return 0;
}
