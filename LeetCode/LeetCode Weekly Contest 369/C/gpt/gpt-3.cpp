class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // Binary search the minimum number of operations
        int left = 0, right = 1e9;
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (isBeautiful(nums, mid, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
    bool isBeautiful(vector<int>& nums, int target, int k) {
        int n = nums.size();
        long long moves = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] < target) {
                moves += target - nums[i];
                if (moves > k) {
                    return false;
                }
            } else {
                break;
            }
        }
        
        return moves <= k;
    }
};
