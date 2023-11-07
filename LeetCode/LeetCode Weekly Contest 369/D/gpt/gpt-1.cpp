class Solution {
public:
    int maximumPoints(vector<vector<int>&> edges, vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<int>> tree(n);
        
        // Build an adjacency list for the tree
        for (const vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        vector<int> result(n, 0); // Initialize an array to store the maximum points for each node
        
        // Perform DFS starting from the root (node 0)
        dfs(0, -1, tree, coins, k, result);
        
        return result[0];
    }
    
    void dfs(int node, int parent, vector<vector<int>>& tree, vector<int>& coins, int k, vector<int>& result) {
        int maxPoints = 0;
        int totalCoins = coins[node];
        
        for (int child : tree[node]) {
            if (child == parent) continue; // Skip the parent node
            dfs(child, node, tree, coins, k, result);
            totalCoins += result[child];
        }
        
        // Calculate the maximum points by either taking all coins with the first way
        // or taking half of the coins with the second way and updating the subtree
        maxPoints = max(maxPoints, totalCoins - k);
        
        for (int child : tree[node]) {
            if (child == parent) continue;
            maxPoints = max(maxPoints, result[node] - result[child] + result[child] / 2);
        }
        
        result[node] = maxPoints;
    }
};
