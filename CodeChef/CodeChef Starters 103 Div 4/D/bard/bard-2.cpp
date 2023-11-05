#include <iostream>
#include <string>

using namespace std;

bool isDivisibleBy8(int n) {
  return (n % 8 == 0);
}

int findMinDigitChanges(int n) {
  string str = to_string(n);

  int minChanges = 0;

  // Check if the last 3 digits are divisible by 8.
  // If not, change the last digit to 0.
  if (!isDivisibleBy8(n % 1000)) {
    str[str.length() - 1] = '0';
    minChanges++;
  }

  // Check if the number is divisible by 8.
  // If not, change the last digit to 8.
  if (!isDivisibleBy8(stoi(str))) {
    str[str.length() - 1] = '8';
    minChanges++;
  }

  return minChanges;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int minChanges = findMinDigitChanges(n);

    cout << minChanges << endl;
  }

  return 0;
}
