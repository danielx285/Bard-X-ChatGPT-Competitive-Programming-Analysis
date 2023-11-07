#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isGoodArray(vector<int>& arr) {
  // Sort the array in ascending order.
  sort(arr.begin(), arr.end());

  // Check if the difference between adjacent elements is the same.
  int diff = arr[1] - arr[0];
  for (int i = 1; i < arr.size() - 1; i++) {
    if (arr[i + 1] - arr[i] != diff) {
      return false;
    }
  }

  return true;
}

bool canMakeArrayGood(vector<int>& arr) {
  // Check if the array is already good.
  if (isGoodArray(arr)) {
    return true;
  }

  // Try all possible permutations of the array.
  for (int i = 0; i < arr.size(); i++) {
    next_permutation(arr.begin(), arr.end());
    if (isGoodArray(arr)) {
      return true;
    }
  }

  return false;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    if (canMakeArrayGood(arr)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
