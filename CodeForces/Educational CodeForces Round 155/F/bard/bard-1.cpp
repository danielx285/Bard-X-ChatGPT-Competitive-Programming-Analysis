#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Hero {
  int health, armor;
  int max_points;
};

bool compare_heroes(const Hero& h1, const Hero& h2) {
  return h1.max_points > h2.max_points;
}

void simulate_game(vector<Hero>& heroes, int x) {
  for (int round = 1;; round++) {
    for (Hero& hero : heroes) {
      if (hero.health == 0) {
        continue;
      }

      if (x < hero.armor) {
        hero.armor -= x;
      } else {
        hero.health -= 1;
        hero.armor = hero.initial_armor;
      }

      if (hero.health == 0) {
        if (heroes.size() == 1) {
          heroes[0].max_points = max(heroes[0].max_points, round);
          return;
        } else {
          heroes.erase(std::remove(heroes.begin(), heroes.end(), hero), heroes.end());
          break;
        }
      }
    }
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<Hero> heroes(n);
    for (int i = 0; i < n; i++) {
      cin >> heroes[i].health;
      cin >> heroes[i].initial_armor;
      heroes[i].max_points = 0;
    }

    for (int x = 1; ; x++) {
      simulate_game(heroes, x);
      if (heroes.empty()) {
        break;
      }
    }

    sort(heroes.begin(), heroes.end(), compare_heroes);
    for (const Hero& hero : heroes) {
      cout << hero.max_points << " ";
    }
    cout << endl;
  }

  return 0;
}
