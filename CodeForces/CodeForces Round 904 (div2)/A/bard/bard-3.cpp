#include <iostream>

using namespace std;

int find_smallest_k_beautiful_integer(int x, int k) {
  // Find the digit sum of x.
  int digit_sum = 0;
  while (x > 0) {
    digit_sum += x % 10;
    x /= 10;
  }

  // Find the smallest multiple of k that is greater than or equal to the digit sum.
  int smallest_multiple_of_k = (digit_sum % k == 0) ? digit_sum : digit_sum + k - (digit_sum % k);

  // Add the smallest multiple of k to x to get the smallest k-beautiful integer greater than or equal to x.
  return x + smallest_multiple_of_k;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int x, k;
    cin >> x >> k;

    cout << find_smallest_k_beautiful_integer(x, k) << endl;
  }

  return 0;
}
