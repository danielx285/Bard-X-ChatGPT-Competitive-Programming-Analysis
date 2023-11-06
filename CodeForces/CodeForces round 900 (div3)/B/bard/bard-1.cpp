#include <iostream>
#include <vector>

using namespace std;

bool isDivisible(int a, int b) {
  return a % b == 0;
}

vector<int> generateIncreasingArray(int n) {
  // Create an empty array to store the result.
  vector<int> result(n);

  // Set the first element of the array to 6.
  result[0] = 6;

  // Generate the remaining elements of the array.
  for (int i = 1; i < n; i++) {
    // Find the smallest integer greater than result[i - 1] that is not divisible by
    // result[i - 1] + result[i - 2] and 3 * result[i].
    int nextElement = result[i - 1] + 1;
    while (isDivisible(nextElement, result[i - 1] + result[i - 2]) ||
           isDivisible(nextElement, 3 * result[i])) {
      nextElement++;
    }

    // Set the current element of the array to the next element.
    result[i] = nextElement;
  }

  return result;
}

int main() {
  // Get the number of test cases.
  int t;
  cin >> t;

  // Iterate over the test cases.
  for (int i = 0; i < t; i++) {
    // Get the size of the array.
    int n;
    cin >> n;

    // Generate the increasing array.
    vector<int> result = generateIncreasingArray(n);

    // Print the array.
    for (int j = 0; j < n; j++) {
      cout << result[j] << " ";
    }
    cout << endl;
  }

  return 0;
}
