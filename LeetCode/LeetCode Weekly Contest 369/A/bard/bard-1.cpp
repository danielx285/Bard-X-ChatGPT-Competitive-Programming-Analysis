class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        // Create a bitmask to store the K-or of the array.
        int bitmask = 0;

        // Iterate over the array and count the number of elements with each bit set.
        for (int num : nums) {
            for (int i = 0; i < 31; i++) {
                if ((num >> i) & 1) {
                    // If the bit i is set in num, increment the count for bit i in the bitmask.
                    bitmask |= (1 << i);
                }
            }
        }

        // Iterate over the bitmask and check if each bit is set in at least k elements of the array.
        // If it is, then set the corresponding bit in the K-or.
        int KOr = 0;
        for (int i = 0; i < 31; i++) {
            if ((bitmask >> i) & 1) {
                if (count(nums.begin(), nums.end(), (1 << i)) >= k) {
                    KOr |= (1 << i);
                }
            }
        }

        return KOr;
    }
};
