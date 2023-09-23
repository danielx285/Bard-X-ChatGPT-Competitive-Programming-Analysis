#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N, M, P;
  cin >> N >> M >> P;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<int> B(M);
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  long long total = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      long long s = A[i] + B[j];
      total += min(s, P);
    }
  }

  cout << total << endl;

  return 0;
}
