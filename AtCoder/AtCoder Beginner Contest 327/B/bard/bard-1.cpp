#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long B;
  cin >> B;

  // Binary search
  int low = 1, high = 1e9;
  while (low <= high) {
    int mid = (low + high) / 2;
    long long power = 1;
    for (int i = 0; i < mid; i++) {
      power *= mid;
    }

    if (power == B) {
      // Found A such that A^A = B
      cout << mid << endl;
      return 0;
    } else if (power < B) {
      // A must be greater than mid
      low = mid + 1;
    } else {
      // A must be less than or equal to mid
      high = mid - 1;
    }
  }

  // No A such that A^A = B
  cout << -1 << endl;
  return 0;
}
