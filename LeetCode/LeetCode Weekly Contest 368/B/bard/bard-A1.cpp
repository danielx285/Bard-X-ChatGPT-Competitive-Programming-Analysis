class Solution {
public:
    int minimumSum(vector<int>& nums) {
        // Sort the array in ascending order.
        sort(nums.begin(), nums.end());

        // Initialize the minimum sum of a mountain triplet.
        int minSum = -1;

        // Iterate over the array and find the first element of a mountain triplet.
        for (int i = 0; i < nums.size() - 2; i++) {
            // If the current element is less than the next element, then it can be the first element of a mountain triplet.
            if (nums[i] < nums[i + 1]) {
                // Find the last element of the mountain triplet.
                int j = i + 1;
                while (j < nums.size() && nums[j] > nums[j - 1]) {
                    j++;
                }

                // If there are at least three elements in the triplet, then calculate the sum of the triplet.
                if (j >= i + 2) {
                    int sum = nums[i] + nums[i + 1] + nums[j - 1];

                    // If the sum of the triplet is smaller than the current minimum sum, then update the minimum sum.
                    if (minSum == -1 || sum < minSum) {
                        minSum = sum;
                    }
                }
            }
        }

        // Return the minimum sum of a mountain triplet, or -1 if no such triplet exists.
        return minSum;
    }
};
