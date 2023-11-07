#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximumPoints(vector<vector<int>&> edges, vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<int>> adj(n);  // Build adjacency list
        for (const vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<pair<int, int>> dp(n);  // dp[node] = {points using first way, points using second way}
        
        function<void(int, int)> dfs = [&](int node, int parent) {
            int pointsFirstWay = coins[node] - k;  // Points if collected using the first way
            int pointsSecondWay = 0;  // Points if collected using the second way
            for (int child : adj[node]) {
                if (child == parent) continue;  // Skip the parent
                dfs(child, node);
                pointsFirstWay += max(dp[child].first, dp[child].second);  // Choose the child's max points
                pointsSecondWay += dp[child].first;  // Collecting coins using the first way from child
            }
            dp[node] = {max(pointsFirstWay, pointsSecondWay), pointsSecondWay};  // Update dp for this node
        };
        
        dfs(0, -1);  // Start DFS from the root (node 0) with no parent
        return max(dp[0].first, dp[0].second);  // Return the maximum of root's two options
    }
};

int main() {
    Solution solution;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
    vector<int> coins = {10, 10, 3, 3};
    int k = 5;
    int result = solution.maximumPoints(edges, coins, k);
    cout << "Maximum points: " << result << endl;  // Output should be 11
    return 0;
}
