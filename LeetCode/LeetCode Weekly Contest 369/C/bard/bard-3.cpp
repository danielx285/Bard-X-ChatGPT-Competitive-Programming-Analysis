class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        // Sort the array in ascending order.
        sort(nums.begin(), nums.end());

        // Initialize the number of increment operations to zero.
        long long increment_operations = 0;

        // Iterate over the array from right to left.
        for (int i = nums.size() - 1; i >= 0; i--) {
            // If the current element is less than k, we need to increment it.
            if (nums[i] < k) {
                // Calculate the number of increments required to make the current element equal to k.
                long long increments = k - nums[i];

                // Update the number of increment operations and the current element.
                increment_operations += increments;
                nums[i] = k;
            }
        }

        // Return the number of increment operations required to make the array beautiful.
        return increment_operations;
    }
};
