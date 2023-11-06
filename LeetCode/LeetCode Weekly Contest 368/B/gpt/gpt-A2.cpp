class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMin(n);
        vector<int> rightMax(n);

        leftMin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], nums[i]);
        }

        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        int minSum = INT_MAX;
        for (int i = 1; i < n - 1; i++) {
            if (leftMin[i] < nums[i] && rightMax[i] > nums[i]) {
                int sum = leftMin[i] + nums[i] + rightMax[i];
                minSum = min(minSum, sum);
            }
        }

        if (minSum == INT_MAX) {
            return -1;
        }

        return minSum;
    }
};
