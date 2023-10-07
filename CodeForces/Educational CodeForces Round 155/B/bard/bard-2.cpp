#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

struct Chip {
  int x, y, cost;
};

bool is_valid(const vector<vector<bool>>& board, int x, int y) {
  return x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && !board[x][y];
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    vector<vector<bool>> board(n, vector<bool>(n, false));
    vector<Chip> chips;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 || j == 0) {
          chips.push_back({i, j, a[i] + b[j]});
          board[i][j] = true;
        }
      }
    }

    int min_cost = 0;
    while (!chips.empty()) {
      Chip chip = chips.back();
      chips.pop_back();

      min_cost += chip.cost;

      for (int i = 0; i < n; i++) {
        if (is_valid(board, chip.x, i)) {
          board[chip.x][i] = true;
          chips.push_back({chip.x, i, a[chip.x] + b[i]});
        }
      }

      for (int i = 0; i < n; i++) {
        if (is_valid(board, i, chip.y)) {
          board[i][chip.y] = true;
          chips.push_back({i, chip.y, a[i] + b[chip.y]});
        }
      }
    }

    cout << min_cost << endl;
  }

  return 0;
}
