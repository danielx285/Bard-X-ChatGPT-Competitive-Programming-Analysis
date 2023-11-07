class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int K_OR = 0;
        for (int bit = 0; bit < 31; bit++) {
            int count = 0;
            for (int num : nums) {
                if ((num & (1 << bit)) != 0) {
                    count++;
                }
            }
            if (count >= k) {
                K_OR |= (1 << bit);
            }
        }
        return K_OR;
    }
};
