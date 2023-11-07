class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        // Build the adjacency list.
        unordered_map<int, vector<int>> adj_list;
        for (auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        // Recursively calculate the maximum points for each node.
        int max_points = 0;
        function<int(int, bool)> dfs = [&](int node, bool parent_collected) {
            int max_points = 0;

            // If the parent has not collected the coins, then we cannot collect the coins at this node.
            if (!parent_collected) {
                return -10000000;
            }

            // Collect all the coins at this node.
            int points = coins[node] - k;
            if (points < 0) {
                points = -points;
            }
            max_points = max(max_points, points);

            // Collect all the coins at this node and reduce the coins of its descendants by half.
            points = floor(coins[node] / 2);
            for (int child : adj_list[node]) {
                points += dfs(child, false);
            }
            max_points = max(max_points, points);

            return max_points;
        };

        // Calculate the maximum points for the root node.
        max_points = dfs(0, true);

        return max_points;
    }
};
