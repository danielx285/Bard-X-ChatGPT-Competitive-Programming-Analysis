#include <iostream>

using namespace std;

int main() {
  int t; // Number of test cases
  cin >> t;

  while (t--) {
    int n, x, d; // Number of buns, buns required per day, and days of survival after food runs out
    cin >> n >> x >> d;

    int total_days = 0; // Total number of days the family can survive

    // If there are enough buns to feed everyone
    if (n >= x * (5 + d)) {
      total_days = 5 + d;
    }
    // If there are not enough buns to feed everyone
    else {
      // Calculate the number of days the buns will last
      int days_with_buns = n / x;

      // Calculate the number of days the family will survive after the buns run out
      int days_without_buns = d - days_with_buns;

      // Calculate the total number of days the family can survive
      total_days = days_with_buns + days_without_buns;
    }

    cout << total_days << endl;
  }

  return 0;
}
