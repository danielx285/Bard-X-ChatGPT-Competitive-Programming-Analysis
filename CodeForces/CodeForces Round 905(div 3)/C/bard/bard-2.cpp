#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int min_operations(vector<int>& arr, int k) {
  int min_ops = 0;
  int product = 1;
  for (int i = 0; i < arr.size(); i++) {
    product *= arr[i];
    if (product % k != 0) {
      int diff = k - (product % k);
      if (arr[i] + diff < k) {
        min_ops++;
      }
    }
  }
  return min_ops;
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
    cout << min_operations(arr, k) << endl;
  }
  return 0;
}
