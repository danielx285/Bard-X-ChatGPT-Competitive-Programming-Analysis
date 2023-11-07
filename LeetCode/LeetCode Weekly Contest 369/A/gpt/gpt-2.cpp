class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int result = 0;
        int n = nums.size();

        for (int bit = 0; bit < 31; bit++) { // Iterate through each bit from 0 to 30
            int count = 0;

            // Count the number of elements with bit set at the current position
            for (int i = 0; i < n; i++) {
                if ((nums[i] & (1 << bit)) != 0) {
                    count++;
                }
            }

            // If the count is greater than or equal to k, set the bit in the result
            if (count >= k) {
                result |= (1 << bit);
            }
        }

        return result;
    }
};
