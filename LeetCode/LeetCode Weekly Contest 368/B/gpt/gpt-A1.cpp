class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 3) {
            return -1; // Mountain triplet requires at least 3 elements
        }
        
        int minSum = INT_MAX; // Initialize the minimum sum to a large value
        int minVal = nums[0]; // Initialize the minimum value to the first element
        int maxVal = INT_MIN; // Initialize the maximum value to a small value
        
        for (int j = 1; j < n - 1; j++) {
            if (nums[j] > minVal && nums[j] < maxVal) {
                minSum = min(minSum, minVal + nums[j] + maxVal);
            }
            minVal = min(minVal, nums[j]);
            maxVal = max(maxVal, nums[j]);
        }
        
        if (minSum == INT_MAX) {
            return -1; // No mountain triplet found
        }
        
        return minSum;
    }
};
