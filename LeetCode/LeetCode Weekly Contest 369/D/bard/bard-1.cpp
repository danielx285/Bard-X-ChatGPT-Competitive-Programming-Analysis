class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        // Create an adjacency list to represent the tree.
        vector<vector<int>> adj(edges.size());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Perform a top-down DFS to calculate the maximum points that can be obtained from each subtree.
        int max_points = 0;
        function<int(int)> dfs = [&](int node) {
            int subtree_points = 0;
            for (const int& child : adj[node]) {
                subtree_points += dfs(child);
            }

            // Consider the two ways to collect coins at the current node.
            int way1_points = coins[node] - k;
            int way2_points = floor(coins[node] / 2) + subtree_points;

            // Return the maximum of the two ways.
            return max(way1_points, way2_points);
        };

        // Start the DFS from the root node.
        max_points = dfs(0);

        return max_points;
    }
};
