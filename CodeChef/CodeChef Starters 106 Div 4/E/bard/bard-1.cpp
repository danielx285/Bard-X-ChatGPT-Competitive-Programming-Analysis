#include <iostream>
#include <vector>

using namespace std;

// Checks if a number is prime.
bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

// Returns a vector of all the odd prime factors of a number.
vector<int> getOddPrimeFactors(int n) {
  vector<int> oddPrimeFactors;
  for (int i = 3; i <= n; i += 2) {
    if (n % i == 0 && isPrime(i)) {
      oddPrimeFactors.push_back(i);
    }
  }
  return oddPrimeFactors;
}

// Checks if Alice can make a move.
bool canAliceMove(int n) {
  vector<int> oddPrimeFactors = getOddPrimeFactors(n);
  return !oddPrimeFactors.empty();
}

// Simulates the game and returns the winner.
string simulateGame(int n) {
  while (n > 1) {
    if (!canAliceMove(n)) {
      return "Alice";
    }

    // Alice makes a move.
    vector<int> oddPrimeFactors = getOddPrimeFactors(n);
    int p = oddPrimeFactors[0];
    n -= p;

    if (!canAliceMove(n)) {
      return "Bob";
    }

    // Bob makes a move.
    vector<int> newOddPrimeFactors = getOddPrimeFactors(n);
    int q = newOddPrimeFactors[0];
    n -= q;
  }

  return "Bob";
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string winner = simulateGame(n);
    cout << winner << endl;
  }

  return 0;
}
