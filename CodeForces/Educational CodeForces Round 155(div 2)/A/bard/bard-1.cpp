#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<pair<int, int>> athletes(n);
    for (int i = 0; i < n; i++) {
      cin >> athletes[i].first >> athletes[i].second;
    }

    // Sort the athletes by strength in ascending order.
    sort(athletes.begin(), athletes.end());

    // Find the minimum endurance of any athlete.
    int min_endurance = athletes[0].second;

    // Choose the weight of the barbell as the minimum endurance of any athlete.
    int w = min_endurance;

    // Check if Polycarp (the 1-st athlete) wins the competition.
    bool polycarp_wins = true;
    for (int i = 1; i < n; i++) {
      if (athletes[i].first <= w && athletes[i].second > w) {
        polycarp_wins = false;
        break;
      }
    }

    // Print the answer.
    if (polycarp_wins) {
      cout << w << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}
