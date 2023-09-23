#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N, X;
  cin >> N >> X;

  int scores[N];
  for (int i = 0; i < N - 1; i++) {
    cin >> scores[i];
  }

  // Sort the scores in ascending order.
  sort(scores, scores + N - 1);

  // Calculate the sum of the N-2 middle scores.
  int sum = 0;
  for (int i = 1; i < N - 1; i++) {
    sum += scores[i];
  }

  // Calculate the minimum score needed in round N to get a final grade of X or higher.
  int minimum_score = X - sum + 1;

  // If the minimum score is not between 0 and 100, then it is impossible to get a final grade of X or higher.
  if (minimum_score < 0 || minimum_score > 100) {
    cout << -1 << endl;
    return 0;
  }

  cout << minimum_score << endl;

  return 0;
}
