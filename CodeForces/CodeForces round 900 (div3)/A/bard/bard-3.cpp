#include <iostream>
#include <vector>

using namespace std;

bool isMostCommonElement(vector<int>& array, int k, int start, int end) {
  int count = 0;
  for (int i = start; i <= end; i++) {
    if (array[i] == k) {
      count++;
    }
  }

  int maxCount = 0;
  for (int i = start; i <= end; i++) {
    int currentCount = 0;
    for (int j = i; j <= end; j++) {
      if (array[j] == array[i]) {
        currentCount++;
      }
    }
    maxCount = max(maxCount, currentCount);
  }

  return count > maxCount;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> array(n);
    for (int i = 0; i < n; i++) {
      cin >> array[i];
    }

    bool found = false;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (isMostCommonElement(array, k, i, j)) {
          found = true;
          break;
        }
      }

      if (found) {
        break;
      }
    }

    if (found) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
