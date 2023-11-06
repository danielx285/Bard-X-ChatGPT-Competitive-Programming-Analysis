class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        // Sort the nums array in ascending order.
        sort(nums.begin(), nums.end());

        // Create a map to store the count of each element in the nums array.
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }

        // Initialize the minimum number of groups required to 1.
        int minGroups = 1;

        // Iterate over the nums array and assign the indices to groups.
        int currentGroupSize = 0;
        int previousElement = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is same as the previous element, then increment the current group size.
            if (nums[i] == previousElement) {
                currentGroupSize++;
            } else {
                // If the current element is different from the previous element, then check if the current group size is valid.
                // If the current group size is valid, then add the current group to the minimum number of groups.
                if (currentGroupSize <= (minGroups + 1)) {
                    minGroups++;
                }

                // Reset the current group size and the previous element.
                currentGroupSize = 1;
                previousElement = nums[i];
            }
        }

        // Check if the current group size is valid.
        // If the current group size is valid, then add the current group to the minimum number of groups.
        if (currentGroupSize <= (minGroups + 1)) {
            minGroups++;
        }

        return minGroups;
    }
};
