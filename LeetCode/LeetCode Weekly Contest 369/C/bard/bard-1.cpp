class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        // Sort the array in ascending order.
        sort(nums.begin(), nums.end());

        // Initialize the number of increment operations required.
        long long increment_operations = 0;

        // Iterate over the array from right to left.
        for (int i = nums.size() - 1; i >= 0; i--) {
            // If the current element is less than k, we need to increment it
            // until it is greater than or equal to k.
            if (nums[i] < k) {
                increment_operations += k - nums[i];
                nums[i] = k;
            }

            // If the current element is greater than or equal to k, we can
            // stop iterating because all the remaining elements will also be
            // greater than or equal to k.
            else if (nums[i] >= k) {
                break;
            }
        }

        // Return the number of increment operations required.
        return increment_operations;
    }
};
