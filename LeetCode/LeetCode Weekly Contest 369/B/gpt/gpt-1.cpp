class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zeros1 = 0, zeros2 = 0;

        for (int num : nums1) {
            sum1 += num;
            if (num == 0) {
                zeros1++;
            }
        }

        for (int num : nums2) {
            sum2 += num;
            if (num == 0) {
                zeros2++;
            }
        }

        long long diff = abs(sum1 - sum2);

        if (diff % 2 != 0 || (diff / 2 > zeros1 + zeros2)) {
            // If the difference is odd or greater than the total number of zeros,
            // it's impossible to make the sums equal.
            return -1;
        }

        long long target = diff / 2;

        for (int& num : nums1) {
            if (num == 0) {
                int add = min(target, 1LL * 1000000); // Add at most 10^6 to each zero.
                num = add;
                target -= add;
            }
        }

        for (int& num : nums2) {
            if (num == 0) {
                int add = min(target, 1LL * 1000000); // Add at most 10^6 to each zero.
                num = add;
                target -= add;
            }
        }

        if (target != 0) {
            // If there's still a remaining target, it's impossible to make the sums equal.
            return -1;
        }

        return sum1; // Both sums are now equal.
    }
};
