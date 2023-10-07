#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> parent(n);
    vector<int> colors(n);
    vector<set<int>> availableColors(n);

    for (int i = 1; i < n; i++) {
        cin >> parent[i];
        parent[i]--;  // Adjust to 0-based indexing
        availableColors[parent[i]].insert(i); // Initialize available colors for each vertex
    }

    int numColors = 0;

    for (int i = 0; i < n; i++) {
        if (availableColors[i].empty()) {
            numColors++;
            colors[i] = numColors;
        }
    }

    cout << numColors << endl;

    for (int i = 1; i < n; i++) {
        if (colors[i] == 0) {
            // Assign a new color to this vertex
            numColors++;
            colors[i] = numColors;
        }
        cout << colors[i] << " ";
    }
    cout << endl;
    cout.flush();

    while (true) {
        int move;
        cin >> move;

        if (move == 1) {
            // You won
            break;
        } else if (move == -1) {
            // You lost or made an incorrect move
            break;
        } else {
            int k;
            cin >> k;
            set<int> edges;
            for (int i = 0; i < k; i++) {
                int e;
                cin >> e;
                edges.insert(e);
            }

            int chosenColor = -1;
            for (int i = 0; i < n; i++) {
                if (edges.count(colors[i])) {
                    chosenColor = colors[i];
                    break;
                }
            }

            cout << chosenColor << endl;
            cout.flush();
        }
    }

    return 0;
}
