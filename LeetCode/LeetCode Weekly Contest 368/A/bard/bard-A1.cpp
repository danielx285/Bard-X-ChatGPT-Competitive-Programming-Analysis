class Solution {
public:
    int minimumSum(vector<int>& nums) {
        // Sort the array in ascending order.
        sort(nums.begin(), nums.end());

        // Initialize the minimum sum of a mountain triplet.
        int minSum = -1;

        // Iterate over the array to find all possible mountain triplets.
        for (int i = 1; i < nums.size() - 1; i++) {
            // If the current element is greater than both its previous and next element, then it is a mountain triplet.
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                // Calculate the sum of the current mountain triplet.
                int sum = nums[i - 1] + nums[i] + nums[i + 1];

                // If the current sum is less than the minimum sum, then update the minimum sum.
                if (minSum == -1 || sum < minSum) {
                    minSum = sum;
                }
            }
        }

        // Return the minimum sum of a mountain triplet, or -1 if no such triplet exists.
        return minSum;
    }
};
