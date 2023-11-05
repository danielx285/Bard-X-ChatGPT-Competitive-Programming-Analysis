#include <iostream>
#include <string>

using namespace std;

bool isDivisibleBy8(int n) {
  return (n % 8 == 0);
}

int findMinDigitsToChange(int n) {
  string str = to_string(n);
  int lastThreeDigits = n % 1000;

  if (isDivisibleBy8(lastThreeDigits)) {
    return 0;
  }

  int minDigitsToChange = 3;
  for (int i = 2; i >= 0; i--) {
    int newLastThreeDigits = lastThreeDigits - (str[str.length() - i - 1] - '0');
    if (isDivisibleBy8(newLastThreeDigits)) {
      minDigitsToChange = min(minDigitsToChange, i + 1);
      break;
    }
  }

  return minDigitsToChange;
}

int findMinDivisibleBy8(int n, int minDigitsToChange) {
  string str = to_string(n);
  int newLastThreeDigits = n % 1000;

  for (int i = 2; i >= 0; i--) {
    newLastThreeDigits = newLastThreeDigits - (str[str.length() - i - 1] - '0');
    if (isDivisibleBy8(newLastThreeDigits)) {
      for (int j = 0; j < minDigitsToChange - 1; j++) {
        newLastThreeDigits += 9;
      }
      break;
    }
  }

  str.replace(str.end() - 3, str.end(), to_string(newLastThreeDigits));
  return stoi(str);
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int minDigitsToChange = findMinDigitsToChange(n);
    int minDivisibleBy8 = findMinDivisibleBy8(n, minDigitsToChange);

    cout << minDivisibleBy8 << endl;
  }

  return 0;
}
