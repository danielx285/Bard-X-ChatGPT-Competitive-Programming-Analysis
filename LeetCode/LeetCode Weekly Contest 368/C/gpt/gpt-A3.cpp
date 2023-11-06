#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int minGroupsForValidAssignment(std::vector<int>& nums) {
        // Create a map to group indices by their corresponding values in nums
        std::unordered_map<int, std::vector<int>> groupMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            groupMap[nums[i]].push_back(i);
        }
        
        // Create a vector to store the sizes of the groups
        std::vector<int> groupSizes;
        for (const auto& entry : groupMap) {
            groupSizes.push_back(entry.second.size());
        }
        
        // Sort the group sizes in non-decreasing order
        std::sort(groupSizes.begin(), groupSizes.end());
        
        int result = 0;
        int n = groupSizes.size();
        int left = 0, right = n - 1;
        
        while (left <= right) {
            // Combine groups from the left and right ends
            if (left == right) {
                result += (groupSizes[left] + 1) / 2;
            } else {
                result += std::min(groupSizes[left], groupSizes[right]);
            }
            left++;
            right--;
        }
        
        return result;
    }
};
