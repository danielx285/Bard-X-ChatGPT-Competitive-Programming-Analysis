#include <vector>

class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<int>> graph(n);
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        int maxPoints = 0;
        
        // DFS function to traverse the tree
        function<void(int, int)> dfs = [&](int node, int parent) {
            int totalCoins = coins[node];
            vector<int> childPoints;
            
            for (int child : graph[node]) {
                if (child != parent) {
                    dfs(child, node);
                    totalCoins += max(0, coins[child] - k); // Collect coins using the first way
                    childPoints.push_back(coins[child]);
                }
            }
            
            if (!childPoints.empty()) {
                sort(childPoints.rbegin(), childPoints.rend());
                for (int i = 0; i < min(2, (int)childPoints.size()); i++) {
                    totalCoins += childPoints[i] / 2; // Collect coins using the second way
                }
            }
            
            maxPoints = max(maxPoints, totalCoins);
        };
        
        dfs(0, -1); // Start DFS from the root (node 0) with no parent
        
        return maxPoints;
    }
};
