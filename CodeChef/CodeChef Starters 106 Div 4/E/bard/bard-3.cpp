#include <iostream>
#include <vector>

using namespace std;

// Returns a list of all odd prime factors of n.
vector<int> GetOddPrimeFactors(int n) {
  vector<int> prime_factors;
  for (int i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      prime_factors.push_back(i);
      n /= i;
    }
  }
  if (n > 1) {
    prime_factors.push_back(n);
  }
  return prime_factors;
}

// Determines who wins the Alice and Bob game, given the initial value n.
string GetWinner(int n) {
  // If n is even or 1, Bob wins immediately.
  if (n % 2 == 0 || n == 1) {
    return "Bob";
  }

  // If n has no odd prime factors, Bob wins again.
  vector<int> prime_factors = GetOddPrimeFactors(n);
  if (prime_factors.empty()) {
    return "Bob";
  }

  // Otherwise, the game is a tie.
  return "Alice";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string winner = GetWinner(n);
    cout << winner << endl;
  }
  return 0;
}
