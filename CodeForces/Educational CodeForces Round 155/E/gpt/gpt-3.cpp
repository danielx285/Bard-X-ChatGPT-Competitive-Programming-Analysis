#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 105;
vector<int> adj[MAXN];
vector<int> colors;
int dist[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    // Calculate the maximum depth of the tree
    int max_depth = 0;
    for (int i = 1; i <= n; i++) {
        int depth = 0;
        for (int j = i; j != 1; j = adj[j][0]) {
            depth++;
        }
        max_depth = max(max_depth, depth);
    }

    // Initialize colors
    int num_colors = max_depth + 1;
    colors.resize(n - 1, 1);

    cout << num_colors << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << colors[i] << " ";
    }
    cout << endl;
    cout.flush();

    // Start the game
    int current_vertex = 1;
    for (int move = 0; move <= max_depth; move++) {
        int response;
        cin >> response;
        if (response == 1) {
            // You won!
            break;
        } else if (response == -1) {
            // You lost or did something incorrect
            break;
        } else {
            int num_edges;
            cin >> num_edges;
            if (move < max_depth) {
                // Choose the color that has the maximum number of edges
                int chosen_color = 1;
                for (int i = 2; i <= num_colors; i++) {
                    if (num_edges[i] > num_edges[chosen_color]) {
                        chosen_color = i;
                    }
                }
                cout << chosen_color << endl;
                cout.flush();
            } else {
                // Choose any color, as long as it's not 1
                int chosen_color = (colors[current_vertex - 2] == 1) ? 2 : 1;
                cout << chosen_color << endl;
                cout.flush();
            }

            // Move to the next vertex
            int next_vertex;
            cin >> next_vertex;
            current_vertex = next_vertex;
        }
    }

    return 0;
}
