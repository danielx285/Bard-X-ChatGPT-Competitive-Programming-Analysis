class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> count; // count the number of occurrences for each value in nums
        for (int num : nums) {
            count[num]++;
        }
        
        // sort the values in nums by their count in descending order
        vector<int> values;
        for (auto& [value, count] : count) {
            values.push_back(value);
        }
        sort(values.rbegin(), values.rend(), [&count](int a, int b) { return count[a] > count[b]; });
        
        // initialize the minimum number of groups
        int minGroups = 0;
        
        // iterate over the values in nums
        for (int value : values) {
            // if the current count is greater than the minimum number of groups, then we need to create a new group
            if (count[value] > minGroups) {
                minGroups++;
            }
        }
        
        // return the minimum number of groups
        return minGroups;
    }
};
