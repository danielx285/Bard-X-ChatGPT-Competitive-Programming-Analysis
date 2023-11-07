class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int result = 0;
        int n = nums.size();
        
        for (int bit = 0; bit <= 31; bit++) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] & (1 << bit)) {
                    count++;
                }
            }
            
            if (count >= k) {
                result |= (1 << bit);
            }
        }
        
        return result;
    }
};
