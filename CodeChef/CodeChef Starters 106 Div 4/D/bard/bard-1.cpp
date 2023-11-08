#include <iostream>
#include <vector>

using namespace std;

// Function to find the number of subarrays with odd bitwise OR
int countOddBitwiseORSubarrays(vector<int>& arr, int k) {
  // Initialize the count of subarrays with odd bitwise OR
  int count = 0;

  // Iterate over all subarrays of length k
  for (int i = 0; i < arr.size() - k + 1; i++) {
    // Calculate the bitwise OR of the current subarray
    int bitwiseOR = 0;
    for (int j = i; j < i + k; j++) {
      bitwiseOR |= arr[j];
    }

    // Check if the bitwise OR of the current subarray is odd
    if (bitwiseOR % 2 == 1) {
      // Increment the count of subarrays with odd bitwise OR
      count++;
    }
  }

  // Return the count of subarrays with odd bitwise OR
  return count;
}

// Main function
int main() {
  // Number of test cases
  int t;
  cin >> t;

  // Iterate over all test cases
  while (t--) {
    // Length of the array and the subarray size
    int n, k;
    cin >> n >> k;

    // Array
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    // Find the number of subarrays with odd bitwise OR
    int count = countOddBitwiseORSubarrays(arr, k);

    // Print the count of subarrays with odd bitwise OR
    cout << count << endl;
  }

  return 0;
}
