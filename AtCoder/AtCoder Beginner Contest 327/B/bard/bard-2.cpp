#include <iostream>

using namespace std;

long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res *= a;
    }
    a *= a;
    b >>= 1;
  }
  return res;
}

int main() {
  long long b;
  cin >> b;

  long long low = 1, high = 10000000000;
  long long mid;
  while (low <= high) {
    mid = (low + high) / 2;
    long long pow = power(mid, mid);
    if (pow == b) {
      cout << mid << endl;
      return 0;
    } else if (pow < b) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << -1 << endl;
  return 0;
}
