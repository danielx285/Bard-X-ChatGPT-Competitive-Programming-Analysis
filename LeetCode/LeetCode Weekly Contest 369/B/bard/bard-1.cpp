#include <vector>
#include <algorithm>

class Solution {
public:
    long long minSum(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Calculate the sum of the two arrays.
        long long sum1 = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            sum1 += nums1[i];
        }
        long long sum2 = 0;
        for (int i = 0; i < nums2.size(); ++i) {
            sum2 += nums2[i];
        }

        // If the sum of the two arrays is already equal, return that sum.
        if (sum1 == sum2) {
            return sum1;
        }

        // Otherwise, we need to replace some 0's in the arrays.
        // We can do this by greedily replacing the smallest 0's in the arrays.
        std::vector<int> zeros1;
        for (int i = 0; i < nums1.size(); ++i) {
            if (nums1[i] == 0) {
                zeros1.push_back(i);
            }
        }
        std::vector<int> zeros2;
        for (int i = 0; i < nums2.size(); ++i) {
            if (nums2[i] == 0) {
                zeros2.push_back(i);
            }
        }

        // Sort the vectors of zeros in ascending order.
        std::sort(zeros1.begin(), zeros1.end());
        std::sort(zeros2.begin(), zeros2.end());

        // Greedily replace the smallest 0's in the arrays.
        long long sum = 0;
        int i = 0;
        int j = 0;
        while (sum1 < sum2) {
            if (i < zeros1.size() && zeros1[i] < zeros2[j]) {
                sum1 += 1;
                nums1[zeros1[i]] = 1;
                i++;
            } else {
                sum2 += 1;
                nums2[zeros2[j]] = 1;
                j++;
            }
        }

        // If we reach the end of either vector of zeros, it means that it is impossible to make the sum of the two arrays equal.
        if (i < zeros1.size() || j < zeros2.size()) {
            return -1;
        }

        // Return the sum of the two arrays.
        return sum1;
    }
};
