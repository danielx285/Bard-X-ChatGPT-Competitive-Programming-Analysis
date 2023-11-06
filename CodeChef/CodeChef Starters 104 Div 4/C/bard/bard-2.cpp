#include <iostream>
#include <vector>

using namespace std;

bool isPossible(int N, int K, vector<int> A) {
  // Sort the chocolates in ascending order.
  sort(A.begin(), A.end());

  // Calculate the minimum number of chocolates required to satisfy the condition.
  int minChocolates = 1;
  for (int i = 1; i < N; i++) {
    if (A[i] - A[i - 1] > K) {
      minChocolates++;
    }
  }

  // If the minimum number of chocolates is greater than the total number of chocolates, then it is not possible to satisfy the condition.
  if (minChocolates > N) {
    return false;
  }

  // Otherwise, it is possible to satisfy the condition.
  return true;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }

    if (isPossible(N, K, A)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
