class Solution {
public:
    int minimumSum(vector<int>& nums) {
        // Sort the array in ascending order.
        sort(nums.begin(), nums.end());

        // Find the minimum sum of a mountain triplet.
        int minSum = INT_MAX;
        for (int i = 1; i < nums.size() - 1; i++) {
            // If the current element is greater than the previous and next elements, then
            // it is the middle element of a mountain triplet.
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                // Calculate the sum of the triplet.
                int sum = nums[i - 1] + nums[i] + nums[i + 1];

                // Update the minimum sum if necessary.
                minSum = min(minSum, sum);
            }
        }

        // Return the minimum sum or -1 if no mountain triplet exists.
        return minSum == INT_MAX ? -1 : minSum;
    }
};
