#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the number of vertices at each depth in the tree
vector<long long> calculateDepths(long long N) {
    vector<long long> depths(N + 1, 0);
    
    // Initialize the depth of the root node to 0
    depths[1] = 0;
    
    // Calculate depths using dynamic programming
    for (long long i = 2; i <= N; i++) {
        depths[i] = depths[i / 2] + 1;
    }
    
    return depths;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        long long N, X, K;
        cin >> N >> X >> K;
        
        vector<long long> depths = calculateDepths(N);
        
        long long ans = 0;
        for (long long i = 1; i <= N; i++) {
            // Calculate the distance between X and vertex i
            long long distance = depths[X] + depths[i] - 2 * depths[(X & i)];
            
            if (distance == K) {
                ans++;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
