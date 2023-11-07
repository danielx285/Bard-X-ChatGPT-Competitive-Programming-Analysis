class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        // Sort the array in ascending order.
        sort(nums.begin(), nums.end());

        // Initialize the number of increment operations required.
        long long increment_operations = 0;

        // Iterate over the array from right to left.
        for (int i = nums.size() - 1; i >= 0; i--) {
            // If the current element is less than k, we need to increment it.
            if (nums[i] < k) {
                // Increment the current element and update the number of increment operations required.
                nums[i]++;
                increment_operations++;

                // Update the value of k to the current element.
                k = nums[i];
            }

            // If the current element is greater than or equal to k, we can stop iterating.
            else {
                break;
            }
        }

        // Return the number of increment operations required.
        return increment_operations;
    }
};
