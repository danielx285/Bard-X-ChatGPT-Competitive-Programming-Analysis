class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 3) {
            return 0; // No need to perform any operations for small arrays.
        }

        sort(nums.begin(), nums.end()); // Sort the array in ascending order.
        long long moves = 0;

        for (int i = 2; i < n; ++i) {
            if (nums[i] >= k) {
                break; // The rest of the array will also be greater than or equal to k.
            }

            int diff = k - nums[i]; // Calculate the difference to reach k.
            moves += diff; // Increment moves by the difference.
            nums[i] += diff; // Update the current element to be equal to k.
        }

        return moves;
    }
};
