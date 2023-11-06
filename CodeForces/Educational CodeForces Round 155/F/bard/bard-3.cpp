#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Hero {
  int health;
  int armor;
  int max_points;
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<Hero> heroes(n);
    for (int i = 0; i < n; i++) {
      cin >> heroes[i].health;
      cin >> heroes[i].armor;
      heroes[i].max_points = 0;
    }

    for (int x = 1; ; x++) {
      // Simulate the game for the current value of x.
      vector<bool> alive(n, true);
      int points = 0;
      for (int round = 1; ; round++) {
        for (int i = 0; i < n; i++) {
          if (alive[i]) {
            // Damage the hero.
            if (x < heroes[i].armor) {
              heroes[i].armor -= x;
            } else {
              heroes[i].health--;
              heroes[i].armor = heroes[i].initial_armor;
            }

            // Check if the hero is dead.
            if (heroes[i].health == 0) {
              alive[i] = false;
              if (points == 0) {
                // The current hero is the last hero to die.
                points = round;
              }
            }
          }
        }

        // Check if the game is over.
        if (count(alive.begin(), alive.end(), true) == 1) {
          break;
        }
      }

      // Update the maximum number of points for each hero.
      for (int i = 0; i < n; i++) {
        heroes[i].max_points = max(heroes[i].max_points, points);
      }

      // Check if we have reached the end of the game.
      if (x > *max_element(heroes.begin(), heroes.end(),
                            [](const Hero& a, const Hero& b) {
                              return a.health < b.health;
                            })) {
        break;
      }
    }

    // Print the maximum number of points for each hero.
    for (int i = 0; i < n; i++) {
      cout << heroes[i].max_points << " ";
    }
    cout << endl;
  }

  return 0;
}
