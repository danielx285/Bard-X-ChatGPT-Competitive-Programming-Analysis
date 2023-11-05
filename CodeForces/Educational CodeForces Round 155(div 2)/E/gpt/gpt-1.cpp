#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 105;

int n, p[MAXN], colors[MAXN];
vector<int> edges[MAXN];
set<int> available_colors;

void dfs(int v) {
    int color;
    if (v == 1) {
        color = 1;
    } else {
        color = colors[v];
    }

    cout << available_colors.size() << endl;
    for (int c : available_colors) {
        cout << c << " ";
    }
    cout << endl;
    cout.flush();

    int result;
    cin >> result;

    if (result == 1) {
        exit(0); // We won
    } else if (result == -1) {
        exit(0); // We lost or made an invalid move
    } else {
        // Update available colors and choose a color for the next move
        available_colors.erase(color);
        available_colors.insert(result);
        colors[v] = result;
    }
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        edges[p[i]].push_back(i);
    }

    // Initialize available colors
    for (int i = 1; i <= n; i++) {
        available_colors.insert(i);
    }

    // Start the game
    dfs(1);

    return 0;
}
