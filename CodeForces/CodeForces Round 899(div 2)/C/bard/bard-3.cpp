#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    // Sort the cards in descending order.
    sort(a.begin(), a.end(), greater<int>());

    // Keep track of the maximum score that can be obtained.
    int max_score = 0;

    // Iterate over the cards in the deck.
    for (int i = 0; i < n; i++) {
      // If the card is odd, add it to the score.
      if (i % 2 == 1) {
        max_score += a[i];
      }
    }

    cout << max_score << endl;
  }

  return 0;
}
