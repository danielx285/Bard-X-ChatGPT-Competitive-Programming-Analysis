#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;

  int previous_digit = -1;
  bool is_321_like = true;

  while (N > 0) {
    int current_digit = N % 10;
    N /= 10;

    if (current_digit >= previous_digit) {
      is_321_like = false;
      break;
    }

    previous_digit = current_digit;
  }

  if (is_321_like) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
