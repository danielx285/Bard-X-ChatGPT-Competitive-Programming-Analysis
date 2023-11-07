#include <vector>
#include <algorithm>

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        // Calculate the sum of both arrays.
        long long sum1 = 0, sum2 = 0;
        for (int num : nums1) {
            sum1 += num;
        }
        for (int num : nums2) {
            sum2 += num;
        }

        // If the sum of the two arrays is already equal, return the sum.
        if (sum1 == sum2) {
            return sum1;
        }

        // Sort the two arrays in decreasing order.
        sort(nums1.begin(), nums1.end(), greater<int>());
        sort(nums2.begin(), nums2.end(), greater<int>());

        // Initialize the minimum equal sum.
        long long minSum = -1;

        // Iterate over the two arrays and replace the 0s with strictly positive integers such that the sum of both arrays becomes equal.
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            // If the sum of both arrays is equal, return the sum.
            if (sum1 == sum2) {
                minSum = sum1;
                break;
            }

            // If the sum of nums1 is greater than the sum of nums2, replace a 0 in nums1 with a strictly positive integer.
            if (sum1 > sum2) {
                sum1 -= nums1[i];
                sum1++;
                i++;
            } else {
                sum2 -= nums2[j];
                sum2++;
                j++;
            }
        }

        // If we reach the end of both arrays and the sum of both arrays is not equal, return -1.
        if (i >= nums1.size() || j >= nums2.size()) {
            minSum = -1;
        }

        return minSum;
    }
};
