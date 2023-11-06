#include <vector>

class Solution {
public:
    int minimumSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> leftMin(n);
        std::vector<int> rightMin(n);
        
        // Calculate the minimum values to the left of each element
        leftMin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = std::min(leftMin[i - 1], nums[i]);
        }
        
        // Calculate the minimum values to the right of each element
        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = std::min(rightMin[i + 1], nums[i]);
        }
        
        int minSum = INT_MAX;
        
        for (int j = 1; j < n - 1; j++) {
            if (nums[j] > leftMin[j] && nums[j] < rightMin[j]) {
                minSum = std::min(minSum, leftMin[j] + nums[j] + rightMin[j]);
            }
        }
        
        if (minSum == INT_MAX) {
            return -1; // No mountain triplet found
        } else {
            return minSum;
        }
    }
};
