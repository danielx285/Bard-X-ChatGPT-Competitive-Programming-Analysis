#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        // Sort the array in ascending order.
        sort(nums.begin(), nums.end());

        // Initialize the minimum sum to -1.
        int minSum = -1;

        // Iterate over the array from index 1 to n - 2.
        for (int i = 1; i < nums.size() - 2; i++) {
            // If the current element is greater than the previous element and less than the next element,
            // then it is the middle element of a mountain triplet.
            if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
                // Calculate the sum of the mountain triplet.
                int sum = nums[i - 1] + nums[i] + nums[i + 1];

                // If the sum is smaller than the current minimum sum, update the minimum sum.
                if (sum < minSum || minSum == -1) {
                    minSum = sum;
                }
            }
        }

        // Return the minimum sum.
        return minSum;
    }
};
