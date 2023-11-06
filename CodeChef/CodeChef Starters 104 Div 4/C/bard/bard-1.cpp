#include <iostream>
#include <vector>

using namespace std;

bool isPossible(int N, int K, vector<int>& A) {
  // Sort the chocolates in ascending order.
  sort(A.begin(), A.end());

  // Calculate the total number of chocolates.
  int totalChocolates = 0;
  for (int i = 0; i < N; i++) {
    totalChocolates += A[i];
  }

  // If the total number of chocolates is less than the number of children, then it is not possible to redistribute the chocolates in a way that satisfies all conditions.
  if (totalChocolates < N) {
    return false;
  }

  // Initialize the minimum number of chocolates that each child should have.
  int minChocolatesPerChild = 1;

  // Check if it is possible to redistribute the chocolates in a way that satisfies all conditions.
  while (minChocolatesPerChild <= totalChocolates) {
    // Calculate the maximum number of chocolates that any child can have.
    int maxChocolatesPerChild = minChocolatesPerChild + K;

    // Check if it is possible to redistribute the chocolates in a way that satisfies all conditions.
    bool isPossible = true;
    int currentChocolateCount = 0;
    int i = 0;
    while (i < N) {
      // If the current child has less than the minimum number of chocolates, then it is not possible to redistribute the chocolates in a way that satisfies all conditions.
      if (currentChocolateCount < minChocolatesPerChild) {
        isPossible = false;
        break;
      }

      // If the current child has more than the maximum number of chocolates, then it is not possible to redistribute the chocolates in a way that satisfies all conditions.
      if (currentChocolateCount > maxChocolatesPerChild) {
        isPossible = false;
        break;
      }

      // Add the chocolates of the current child to the current chocolate count.
      currentChocolateCount += A[i];
      i++;
    }

    // If it is possible to redistribute the chocolates in a way that satisfies all conditions, then return true.
    if (isPossible) {
      return true;
    }

    // Increment the minimum number of chocolates that each child should have.
    minChocolatesPerChild++;
  }

  // If it is not possible to redistribute the chocolates in a way that satisfies all conditions, then return false.
  return false;
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
