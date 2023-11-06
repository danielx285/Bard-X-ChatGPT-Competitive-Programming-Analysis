#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;

int n;
vector<int> a(MAXN);
vector<vector<int>> adj(MAXN);
vector<long long> ans(MAXN);

void dfs(int u, int parent, int xor_val) {
    xor_val ^= a[u]; // Update XOR value for the current subtree rooted at u
    
    // Calculate the cost for this vertex
    ans[u] = xor_val;
    
    // Traverse all children of u
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u, xor_val);
        }
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        
        // Initialize data structures
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            ans[i] = 0;
        }
        
        // Read input values
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        // Read tree edges
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Perform DFS to calculate the answer
        dfs(1, 0, 0);
        
        // Output the results
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
