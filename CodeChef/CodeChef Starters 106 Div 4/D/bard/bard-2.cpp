#include <bits/stdc++.h>

using namespace std;

// Function to count the number of subarrays of length K with odd bitwise OR.
int countSubarraysWithOddBitwiseOR(vector<int> &A, int K) {
  // Keep track of the number of odd subarrays.
  int oddSubarrayCount = 0;

  // Initialize the current bitwise OR of the subarray.
  int currentBitwiseOR = 0;

  // Iterate over the array.
  for (int i = 0; i < A.size(); i++) {
    // Add the current element to the bitwise OR.
    currentBitwiseOR |= A[i];

    // If the length of the subarray is K, check if its bitwise OR is odd.
    if (i >= K - 1) {
      // If the bitwise OR is odd, increment the odd subarray count.
      if (currentBitwiseOR % 2 == 1) {
        oddSubarrayCount++;
      }

      // Remove the first element from the bitwise OR.
      currentBitwiseOR ^= A[i - K + 1];
    }
  }

  // Return the number of odd subarrays.
  return oddSubarrayCount;
}

// Main function.
int main() {
  // Number of test cases.
  int T;
  cin >> T;

  // Iterate over the test cases.
  while (T--) {
    // Length of the array and the subarray size.
    int N, K;
    cin >> N >> K;

    // Array of elements.
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }

    // Count the number of subarrays of length K with odd bitwise OR.
    int oddSubarrayCount = countSubarraysWithOddBitwiseOR(A, K);

    // Print the answer.
    cout << oddSubarrayCount << endl;
  }

  return 0;
}
