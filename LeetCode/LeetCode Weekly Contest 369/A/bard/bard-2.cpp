class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int kOr = 0;
        for (int i = 0; i < 31; i++) {
            int count = 0;
            for (int num : nums) {
                if (num & (1 << i)) {
                    count++;
                }
            }
            if (count >= k) {
                kOr |= (1 << i);
            }
        }
        return kOr;
    }
};
