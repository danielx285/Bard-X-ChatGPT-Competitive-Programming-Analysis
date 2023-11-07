class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int result = 0;
        int mask = 0;

        for (int bit = 0; bit < 31; bit++) {
            int count = 0;
            for (int num : nums) {
                if (num & (1 << bit)) {
                    count++;
                }
            }
            
            if (count >= k) {
                mask |= (1 << bit);
            }
        }

        for (int num : nums) {
            result |= (num & mask);
        }

        return result;
    }
};
