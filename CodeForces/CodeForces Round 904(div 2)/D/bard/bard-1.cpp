#include <unordered_map>
#include <vector>

using namespace std;

int numGoodPairs(vector<int>& nums) {
  unordered_map<int, int> freq;
  int goodPairs = 0;

  for (int num : nums) {
    freq[num]++;
  }

  for (auto& [num, count] : freq) {
    if (count < 2) {
      continue;
    }

    goodPairs += (count * (count - 1)) / 2;
  }

  return goodPairs;
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

    int goodPairs = numGoodPairs(nums);
    cout << goodPairs << endl;
  }

  return 0;
}
