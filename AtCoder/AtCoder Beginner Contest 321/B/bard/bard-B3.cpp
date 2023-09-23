#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N, X;
  cin >> N >> X;

  // Read the scores from the previous rounds.
  int scores[N - 1];
  for (int i = 0; i < N - 1; i++) {
    cin >> scores[i];
  }

  // Sort the scores in ascending order.
  sort(scores, scores + N - 1);

  // Calculate the minimum score needed in round N to get a final grade of X or higher.
  int minScore = X - scores[0] - scores[N - 2];
  if (minScore < 0) {
    cout << -1 << endl;
    return 0;
  }

  cout << minScore << endl;
  return 0;
}
