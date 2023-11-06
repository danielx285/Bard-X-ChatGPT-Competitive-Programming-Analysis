#include <iostream>
#include <vector>
#include <map>

using namespace std;

int countGoodPairs(vector<int>& nums) {
  int n = nums.size();
  map<int, int> freq;
  for (int i = 0; i < n; i++) {
    freq[nums[i]]++;
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (nums[i] != nums[j] && freq[nums[i]] == 1 && freq[nums[j]] == 1) {
        count++;
      }
    }
  }
  return count;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    int count = countGoodPairs(nums);
    cout << count << endl;
  }
  return 0;
}
