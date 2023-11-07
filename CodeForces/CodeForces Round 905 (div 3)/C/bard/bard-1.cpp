#include <iostream>
#include <vector>

using namespace std;

int minOperations(vector<int> &a, int k) {
  int n = a.size();
  vector<int> arr1(n);
  vector<int> arr2(n);

  // Calculate arr1[i] and arr2[i] for all i.
  for (int i = 0; i < n; i++) {
    arr1[i] = k - a[i] % k;
    arr2[i] = k;
  }

  // Sort arr1 and arr2 in decreasing order.
  sort(arr1.begin(), arr1.end(), greater<int>());
  sort(arr2.begin(), arr2.end(), greater<int>());

  // Initialize the answer.
  int ans = 0;

  // Iterate over arr1 and arr2, and choose the operation that minimizes ans.
  for (int i = 0; i < n; i++) {
    if (arr1[i] < arr2[i]) {
      ans += arr1[i];
    } else {
      ans += arr2[i];
      break;
    }
  }

  return ans;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int ans = minOperations(a, k);
    cout << ans << endl;
  }

  return 0;
}
