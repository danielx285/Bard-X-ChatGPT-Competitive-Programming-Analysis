#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool existsSubsegmentWhereKIsMostCommon(vector<int>& arr, int k) {
  // Create a map to store the frequency of each element.
  map<int, int> freqMap;
  for (int element : arr) {
    freqMap[element]++;
  }

  // Find the most frequent element in the array.
  int maxFreq = 0;
  int mostFreqElement = -1;
  for (auto& pair : freqMap) {
    if (pair.second > maxFreq) {
      maxFreq = pair.second;
      mostFreqElement = pair.first;
    }
  }

  // Check if there exists a subsegment where k is the most common element.
  // We can do this by keeping track of the frequency of k in the current subsegment.
  int kFreqInCurrentSubsegment = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == k) {
      kFreqInCurrentSubsegment++;
    }

    // If the frequency of k in the current subsegment is greater than the frequency
    // of the most frequent element in the array, then we have found a subsegment
    // where k is the most common element.
    if (kFreqInCurrentSubsegment > maxFreq) {
      return true;
    }

    // If the frequency of k in the current subsegment is equal to the frequency
    // of the most frequent element in the array, and we are at the end of the array,
    // then we have also found a subsegment where k is the most common element.
    if (kFreqInCurrentSubsegment == maxFreq && i == arr.size() - 1) {
      return true;
    }

    // If the frequency of k in the current subsegment is equal to the frequency
    // of the most frequent element in the array, but we are not at the end of the
    // array, then we need to update the frequency of k in the current subsegment
    // to take into account the next element in the array.
    if (kFreqInCurrentSubsegment == maxFreq && i < arr.size() - 1) {
      if (arr[i + 1] == k) {
        kFreqInCurrentSubsegment++;
      } else {
        kFreqInCurrentSubsegment--;
      }
    }
  }

  // If we reach this point, then there does not exist a subsegment where k is the most common element.
  return false;
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

    if (existsSubsegmentWhereKIsMostCommon(arr, k)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
