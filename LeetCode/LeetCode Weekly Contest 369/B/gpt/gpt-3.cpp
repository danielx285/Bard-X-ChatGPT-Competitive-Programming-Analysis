class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        int zeros1 = count(nums1.begin(), nums1.end(), 0);
        int zeros2 = count(nums2.begin(), nums2.end(), 0);

        long long diff = abs(sum1 - sum2);

        if (diff % 2 != 0) {
            // If the difference is odd, it's impossible to make the sums equal.
            return -1;
        }

        long long target = diff / 2;

        for (int& num : nums1) {
            if (num == 0 && zeros1 > 0) {
                if (target >= 5) {
                    num = 5;
                    target -= 5;
                } else if (target >= 2) {
                    num = 2;
                    target -= 2;
                } else {
                    num = 1;
                    target--;
                }
                zeros1--;
            }
        }

        for (int& num : nums2) {
            if (num == 0 && zeros2 > 0) {
                if (target >= 5) {
                    num = 5;
                    target -= 5;
                } else if (target >= 2) {
                    num = 2;
                    target -= 2;
                } else {
                    num = 1;
                    target--;
                }
                zeros2--;
            }
        }

        return sum1 + sum2; // Both sums are now equal.
    }
};
