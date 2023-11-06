class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        // Sort the nums array in ascending order.
        sort(nums.begin(), nums.end());

        // Create a map to store the frequency of each number in the nums array.
        unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }

        // Initialize the number of groups to 0.
        int groups = 0;

        // Iterate over the nums array.
        for (int i = 0; i < nums.size(); i++) {
            // If the frequency of the current number is greater than 1, then we need to create a new group for it.
            if (frequency[nums[i]] > 1) {
                groups++;
            }

            // Reduce the frequency of the current number by 1.
            frequency[nums[i]]--;
        }

        // Return the number of groups.
        return groups;
    }
};
