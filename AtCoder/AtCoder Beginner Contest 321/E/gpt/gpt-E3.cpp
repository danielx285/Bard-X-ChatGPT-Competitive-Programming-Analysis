#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the number of vertices at each level of the tree.
vector<long long> calculateLevels(long long N) {
    vector<long long> levels;
    long long level = 0;
    while (N > 0) {
        levels.push_back(N);
        N /= 2;
        level++;
    }
    return levels;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        long long N, X, K;
        cin >> N >> X >> K;

        // Calculate the levels of the tree.
        vector<long long> levels = calculateLevels(N);

        if (K >= levels.size()) {
            // If K is greater than the maximum possible level, there are 0 vertices at that level.
            cout << "0" << endl;
        } else {
            long long count = 0;
            long long current = X;

            // Traverse up the tree to find vertices at level K.
            for (int i = 0; i <= K; i++) {
                if (i == K) {
                    // If we reach level K, increment the count.
                    count++;
                    break;
                }

                // If we can't go further up the tree, break the loop.
                if (current == 1) break;

                // Calculate the number of vertices at the next level.
                long long next_level = levels[i + 1];

                // If we can move to the left child, add the vertices in the right subtree to the count.
                if (current % 2 == 0) {
                    count += (next_level - current);
                }

                // Move up to the parent node.
                current /= 2;
            }

            cout << count << endl;
        }
    }

    return 0;
}
