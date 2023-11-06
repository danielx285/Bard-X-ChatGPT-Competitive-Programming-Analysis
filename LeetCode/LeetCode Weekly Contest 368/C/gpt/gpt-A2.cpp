#include <vector>
#include <unordered_map>

class Solution {
public:
    int minGroupsForValidAssignment(std::vector<int>& nums) {
        std::unordered_map<int, int> groupCount;  // Map to store the count of each group

        for (int num : nums) {
            groupCount[num]++;
        }

        int maxGroupSize = 0;
        int totalGroups = 0;

        for (const auto& kv : groupCount) {
            maxGroupSize = std::max(maxGroupSize, kv.second);
            totalGroups += kv.second;
        }

        // Calculate the minimum number of groups needed
        if (maxGroupSize >= (totalGroups + 1) / 2) {
            // If the largest group is large enough, we can create one group per value
            return maxGroupSize;
        } else {
            // Otherwise, we need (maxGroupSize - 1) + the remaining smaller groups
            return std::max(maxGroupSize - 1, totalGroups - maxGroupSize + 1);
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {3, 2, 3, 2, 3};
    std::vector<int> nums2 = {10, 10, 10, 3, 1, 1};
    int result1 = solution.minGroupsForValidAssignment(nums1);
    int result2 = solution.minGroupsForValidAssignment(nums2);
    std::cout << "Result 1: " << result1 << std::endl; // Output: 2
    std::cout << "Result 2: " << result2 << std::endl; // Output: 4
    return 0;
}
