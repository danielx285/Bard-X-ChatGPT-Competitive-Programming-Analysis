class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        long long operations = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] < k) {
                int diff = k - nums[i];
                operations += diff;
                nums[i] += diff;
            }
        }
        
        return operations;
    }
};
