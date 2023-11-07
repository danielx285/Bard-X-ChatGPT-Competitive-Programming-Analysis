#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {

        // Calculate the sum of the two arrays.
        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i < nums1.size(); i++) {
            sum1 += nums1[i];
        }
        for (int i = 0; i < nums2.size(); i++) {
            sum2 += nums2[i];
        }

        // If the sum of the two arrays is not equal, then it is impossible to make them equal.
        if (sum1 != sum2) {
            return -1;
        }

        // Count the number of zeros in the two arrays.
        int count0 = 0;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == 0) {
                count0++;
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (nums2[i] == 0) {
                count0++;
            }
        }

        // If there are no zeros in the two arrays, then the minimum equal sum is already achieved.
        if (count0 == 0) {
            return sum1;
        }

        // Sort the two arrays in decreasing order.
        sort(nums1.begin(), nums1.end(), greater<int>());
        sort(nums2.begin(), nums2.end(), greater<int>());

        // Replace the zeros in the two arrays with the largest elements from the other array.
        long long minSum = 0;
        for (int i = 0; i < count0; i++) {
            if (nums1[i] == 0) {
                minSum += nums2[i];
            } else if (nums2[i] == 0) {
                minSum += nums1[i];
            }
        }

        return minSum;
    }
};
