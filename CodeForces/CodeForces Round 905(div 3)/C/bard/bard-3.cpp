#include <bits/stdc++.h>

using namespace std;

// Function to find the minimum number of operations needed to make the product of all the numbers in the array divisible by k.
int minOperations(vector<int> &a, int k) {
  // Calculate the product of all the numbers in the array.
  int product = 1;
  for (int i = 0; i < a.size(); i++) {
    product *= a[i];
  }

  // Calculate the remainder when the product is divided by k.
  int remainder = product % k;

  // If the remainder is 0, then no operations are needed.
  if (remainder == 0) {
    return 0;
  }

  // Find the minimum number of operations needed to make the remainder 0.
  int minOperations = remainder;
  for (int i = 0; i < a.size(); i++) {
    int newRemainder = (remainder - a[i]) % k;
    if (newRemainder < 0) {
      newRemainder += k;
    }

    minOperations = min(minOperations, newRemainder);
  }

  return minOperations;
}

int main() {
  // Number of test cases.
  int t;
  cin >> t;

  while (t--) {
    // Size of the array and the number k.
    int n, k;
    cin >> n >> k;

    // Array a.
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    // Find the minimum number of operations needed.
    int minOperations = minOperations(a, k);

    // Print the output.
    cout << minOperations << endl;
  }

  return 0;
}
