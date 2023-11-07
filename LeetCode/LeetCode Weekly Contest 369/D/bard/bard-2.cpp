class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        // Create a graph from the edges.
        vector<vector<int>> adj_list(coins.size());
        for (auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        
        // Create a memo table to store the maximum points that can be obtained from a subtree rooted at a given node.
        vector<int> memo(coins.size(), -1);
        
        // Recursive function to calculate the maximum points that can be obtained from a subtree rooted at a given node.
        int dfs(int node) {
            if (memo[node] != -1) {
                return memo[node];
            }
            
            int max_points = 0;
            
            // Calculate the maximum points that can be obtained by collecting all the coins from the current node and its subtree.
            int points1 = coins[node] - k;
            if (points1 < 0) {
                points1 -= abs(points1);
            }
            
            for (auto& neighbor : adj_list[node]) {
                points1 += dfs(neighbor);
            }
            
            // Calculate the maximum points that can be obtained by collecting only half of the coins from the current node and its subtree.
            int points2 = floor(coins[node] / 2);
            
            for (auto& neighbor : adj_list[node]) {
                coins[neighbor] = floor(coins[neighbor] / 2);
                points2 += dfs(neighbor);
            }
            
            // Update the memo table with the maximum points that can be obtained from the current node and its subtree.
            memo[node] = max(points1, points2);
            
            return memo[node];
        }
        
        // Return the maximum points that can be obtained by collecting coins from all the tree nodes.
        return dfs(0);
    }
};
