#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumSum(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return -1; // Not enough elements for a mountain triplet.
        }

        std::vector<int> left(n, 0);
        std::vector<int> right(n, 0);

        // Calculate the minimum value to the left of each element.
        left[0] = nums[0];
        for (int i = 1; i < n; i++) {
            left[i] = std::min(left[i - 1], nums[i]);
        }

        // Calculate the minimum value to the right of each element.
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = std::min(right[i + 1], nums[i]);
        }

        int minSum = INT_MAX;

        // Iterate through the elements to find a mountain triplet.
        for (int j = 1; j < n - 1; j++) {
            if (nums[j] > left[j - 1] && nums[j] > right[j + 1]) {
                minSum = std::min(minSum, nums[j] + left[j - 1] + right[j + 1]);
            }
        }

        return (minSum == INT_MAX) ? -1 : minSum;
    }
};
