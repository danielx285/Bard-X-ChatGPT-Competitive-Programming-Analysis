#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(int N, int K, vector<int> &A) {
  // Sort the chocolates in ascending order.
  sort(A.begin(), A.end());

  // If the difference between the first and the last chocolate is greater than K, then it is not possible to redistribute the chocolates in the desired way.
  if (A[N - 1] - A[0] > K) {
    return false;
  }

  // Initialize the number of chocolates given to each child to 1.
  vector<int> B(N, 1);

  // Distribute the remaining chocolates in a way that the difference of chocolates between any pair of children is not more than K.
  for (int i = 1; i < N; i++) {
    int diff = A[i] - A[i - 1];
    if (diff > K) {
      return false;
    } else {
      B[i] += diff;
    }
  }

  // Check if all children have at least 1 chocolate.
  for (int i = 0; i < N; i++) {
    if (B[i] == 0) {
      return false;
    }
  }

  // If we reach here, it means that it is possible to redistribute the chocolates in the desired way.
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

    bool isPossible = isPossible(N, K, A);

    if (isPossible) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
