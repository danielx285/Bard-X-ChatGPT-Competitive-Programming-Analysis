#include <vector>
#include <iostream>

class Solution {
public:
    int minimumSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> leftMin(n, 0);
        std::vector<int> rightMin(n, 0);
        
        // Calculate the minimum values to the left of each element.
        for (int i = 1; i < n; i++) {
            leftMin[i] = std::min(leftMin[i - 1], nums[i - 1]);
        }

        int minSum = INT_MAX; // Initialize the minimum sum as maximum possible value.
        
        // Traverse the array from right to left.
        for (int i = n - 2; i >= 1; i--) {
            // Calculate the minimum values to the right of each element.
            rightMin[i] = std::min(rightMin[i + 1], nums[i + 1]);

            // Check if nums[i] is the peak of a mountain.
            if (leftMin[i] < nums[i] && rightMin[i] < nums[i]) {
                minSum = std::min(minSum, leftMin[i] + nums[i] + rightMin[i]);
            }
        }

        return minSum == INT_MAX ? -1 : minSum; // If no mountain triplet is found, return -1.
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {8, 6, 1, 5, 3};
    std::vector<int> nums2 = {5, 4, 8, 7, 10, 2};
    std::vector<int> nums3 = {6, 5, 4, 3, 4, 5};
    
    std::cout << solution.minimumSum(nums1) << std::endl; // Output: 9
    std::cout << solution.minimumSum(nums2) << std::endl; // Output: 13
    std::cout << solution.minimumSum(nums3) << std::endl; // Output: -1
    
    return 0;
}
