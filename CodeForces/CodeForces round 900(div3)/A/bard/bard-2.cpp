#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool checkSubsegment(vector<int>& arr, int k, int start, int end) {
  // Count the number of occurrences of k in the subsegment.
  int count = 0;
  for (int i = start; i <= end; i++) {
    if (arr[i] == k) {
      count++;
    }
  }

  // Check if k is the most common element in the subsegment.
  for (int i = start; i <= end; i++) {
    int otherCount = 0;
    for (int j = start; j <= end; j++) {
      if (arr[j] == arr[i] && j != i) {
        otherCount++;
      }
    }
    if (otherCount > count) {
      return false;
    }
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    // Check if there exists a subsegment where k is the most common element.
    bool found = false;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (checkSubsegment(arr, k, i, j)) {
          found = true;
          break;
        }
      }
      if (found) {
        break;
      }
    }

    // Print the answer.
    if (found) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
