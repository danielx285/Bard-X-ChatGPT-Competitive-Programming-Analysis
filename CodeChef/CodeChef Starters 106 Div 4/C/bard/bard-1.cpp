#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    // Calculate the number of ways to choose 2 players from n players.
    int ways = n * (n - 1) / 2;

    cout << ways << endl;
  }

  return 0;
}
