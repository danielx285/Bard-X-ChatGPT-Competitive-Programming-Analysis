#include <iostream>
#include <vector>

using namespace std;

bool isGoodPair(vector<int>& A, vector<int>& B) {
  int N = A.size();
  int M = B.size();

  // Create a vector to store the values of X.
  vector<int> X(N, -1);

  // Iterate over the elements of A and B.
  for (int i = 0; i < M; i++) {
    // If X[A[i]] is already set and it is not equal to X[B[i]], then the pair is not good.
    if (X[A[i]] != -1 && X[A[i]] != X[B[i]]) {
      return false;
    }

    // If X[A[i]] is not set, then set it to X[B[i]].
    if (X[A[i]] == -1) {
      X[A[i]] = X[B[i]];
    }
  }

  // Check if all the elements of X are set.
  for (int i = 0; i < N; i++) {
    if (X[i] == -1) {
      return false;
    }
  }

  // The pair is good.
  return true;
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
  }

  if (isGoodPair(A, B)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
