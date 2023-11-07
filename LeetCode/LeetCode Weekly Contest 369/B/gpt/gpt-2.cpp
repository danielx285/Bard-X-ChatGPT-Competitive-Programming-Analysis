class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        
        int zeros1 = count(nums1.begin(), nums1.end(), 0);
        int zeros2 = count(nums2.begin(), nums2.end(), 0);
        
        long long diff = abs(sum1 - sum2);
        
        if (diff % 2 != 0 || (diff / 2) > (zeros1 + zeros2))
            return -1;
        
        long long increment = diff / 2;
        
        for (int& num : nums1) {
            if (num == 0 && increment > 0) {
                int add = min(increment, 1000000LL); // Cap the increment at 10^6
                num += add;
                increment -= add;
            }
        }
        
        for (int& num : nums2) {
            if (num == 0 && increment > 0) {
                int add = min(increment, 1000000LL); // Cap the increment at 10^6
                num += add;
                increment -= add;
            }
        }
        
        return accumulate(nums1.begin(), nums1.end(), 0LL);
    }
};
