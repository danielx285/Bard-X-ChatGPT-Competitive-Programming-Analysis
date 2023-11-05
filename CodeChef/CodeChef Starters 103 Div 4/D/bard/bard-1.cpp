#include <iostream>
#include <string>

using namespace std;

bool isDivisibleBy8(int n) {
  return (n % 8 == 0);
}

int findMinDigitChangesToMakeDivisibleBy8(int n) {
  // Convert the integer to a string.
  string nStr = to_string(n);

  // Iterate over the digits of the string in reverse order.
  for (int i = nStr.length() - 1; i >= 0; i--) {
    // If the digit is not divisible by 8, try changing it to the next even digit.
    if (nStr[i] % 8 != 0) {
      nStr[i] = (nStr[i] + 2) % 10;
      return nStr.length() - i;
    }
  }

  // If we reach here, the number is already divisible by 8.
  return 0;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int minDigitChanges = findMinDigitChangesToMakeDivisibleBy8(n);

    // If the number of digit changes is 0, then the number is already divisible by 8.
    if (minDigitChanges == 0) {
      cout << n << endl;
    } else {
      // Otherwise, print the number with the minimum digit changes.
      cout << n + minDigitChanges << endl;
    }
  }

  return 0;
}
