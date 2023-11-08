#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Read the input.
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  vector<int> B(M);
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
  }

  // Check if the given pair of sequences is good.
  bool isGood = true;
  for (int i = 0; i < M; i++) {
    if (A[i] != B[i]) {
      isGood = false;
      break;
    }
  }

  // Print the output.
  if (isGood) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
