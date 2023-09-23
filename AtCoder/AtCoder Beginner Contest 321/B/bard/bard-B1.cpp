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

  // Calculate the minimum score needed in round N.
  int target_sum = X - (scores[0] + scores[1] + ... + scores[N - 3]);
  int min_score = max(0, target_sum - (N - 2) * 100);

  // Print the answer.
  if (min_score > 100) {
    cout << -1 << endl;
  } else {
    cout << min_score << endl;
  }

  return 0;
}
