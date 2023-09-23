#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, M, P;
  cin >> N >> M >> P;
  vector<int> A(N);
  vector<int> B(M);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }

  // Sort the main dishes and side dishes in ascending order.
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  // Initialize the total price.
  long long total_price = 0;

  // Iterate over all pairs of main dishes and side dishes.
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      // Calculate the sum of the prices of the main dish and the side dish.
      long long sum = A[i] + B[j];

      // Calculate the price of the set meal.
      long long price = min(sum, P);

      // Add the price of the set meal to the total price.
      total_price += price;
    }
  }

  // Print the answer.
  cout << total_price << endl;

  return 0;
}
