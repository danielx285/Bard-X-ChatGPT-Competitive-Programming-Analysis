class Solution {
public:
    int minimumSum(vector<int>& nums) {
        // Sort the array in ascending order.
        sort(nums.begin(), nums.end());

        // Initialize the minimum sum.
        int minSum = -1;

        // Iterate over the array to find a mountain triplet.
        for (int i = 1; i < nums.size() - 1; i++) {
            // If the current element is greater than the previous element and less than the next element,
            // then we have a mountain triplet.
            if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
                // Calculate the sum of the mountain triplet.
                int sum = nums[i - 1] + nums[i] + nums[i + 1];

                // Update the minimum sum if necessary.
                if (minSum == -1 || sum < minSum) {
                    minSum = sum;
                }
            }
        }

        return minSum;
    }
};
