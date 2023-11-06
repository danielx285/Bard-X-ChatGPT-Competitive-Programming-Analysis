class Solution {
public:
    int minimumSum(vector<int>& nums) {
        // Sort the array in ascending order.
        sort(nums.begin(), nums.end());

        // Initialize the minimum sum of a mountain triplet to -1.
        int minSum = -1;

        // Iterate over the array and find all possible mountain triplets.
        for (int i = 0; i < nums.size() - 2; i++) {
            // Find the indices of the two elements in the triplet that are greater than the first element.
            int j = i + 1;
            int k = i + 2;
            while (k < nums.size() && nums[k] <= nums[i]) {
                k++;
            }

            // If the indices j and k are valid, then the triplet (i, j, k) is a mountain triplet.
            if (j < k) {
                // Calculate the sum of the mountain triplet.
                int sum = nums[i] + nums[j] + nums[k];

                // Update the minimum sum of a mountain triplet if necessary.
                if (minSum == -1 || sum < minSum) {
                    minSum = sum;
                }
            }
        }

        // Return the minimum sum of a mountain triplet.
        return minSum;
    }
};
