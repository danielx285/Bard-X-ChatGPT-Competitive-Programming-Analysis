#include <vector>
#include <unordered_map>

class Solution {
public:
    int minGroupsForValidAssignment(std::vector<int>& nums) {
        std::unordered_map<int, int> count; // Count of each distinct value
        int maxCount = 0; // Maximum count of any distinct value

        // Count the occurrences of each distinct value in nums
        for (int num : nums) {
            count[num]++;
            maxCount = std::max(maxCount, count[num]);
        }

        // Calculate the number of groups required
        int totalGroups = 0;
        for (const auto& entry : count) {
            int numCount = entry.second;
            totalGroups += (numCount - 1) * (maxCount - 1); // Calculate groups using the maximum count
        }

        // Handle the left-over values (values that don't have maxCount occurrences)
        int leftOver = (nums.size() - maxCount * (maxCount - 1));
        totalGroups += leftOver;

        return totalGroups;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {3, 2, 3, 2, 3};
    std::vector<int> nums2 = {10, 10, 10, 3, 1, 1};

    int result1 = solution.minGroupsForValidAssignment(nums1); // Should return 2
    int result2 = solution.minGroupsForValidAssignment(nums2); // Should return 4

    std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;

    return 0;
}
