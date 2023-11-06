class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int minSum = INT_MAX;
        
        for (int j = 1; j < n - 1; ++j) {
            int maxLeft = -1;
            int maxRight = -1;
            
            // Find the maximum value to the left of j
            for (int i = 0; i < j; ++i) {
                if (nums[i] < nums[j]) {
                    maxLeft = max(maxLeft, nums[i]);
                }
            }
            
            // Find the maximum value to the right of j
            for (int k = j + 1; k < n; ++k) {
                if (nums[k] < nums[j]) {
                    maxRight = max(maxRight, nums[k]);
                }
            }
            
            // If valid mountains exist to the left and right, update the minimum sum
            if (maxLeft != -1 && maxRight != -1) {
                int currentSum = maxLeft + nums[j] + maxRight;
                minSum = min(minSum, currentSum);
            }
        }
        
        return (minSum == INT_MAX) ? -1 : minSum;
    }
};
