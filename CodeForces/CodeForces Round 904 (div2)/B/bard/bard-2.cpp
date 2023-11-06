#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    // Create an array to store the number of swaps required for each value of i.
    int swaps[n + 1];
    for (int i = 0; i <= n; i++) {
      swaps[i] = -1;
    }

    // Initialize the number of swaps required for i = 1.
    swaps[1] = 0;

    // Iterate over the values of i from 2 to n.
    for (int i = 2; i <= n; i++) {
      // If the number is not divisible by 2^i, then there is no answer.
      if ((s[n - i] == '0' && (i & 1)) || (s[n - i] == '1' && !(i & 1))) {
        swaps[i] = -1;
        continue;
      }

      // Find the minimum number of swaps required to make the number divisible by 2^i.
      int minSwaps = swaps[i - 1];
      for (int j = n - i - 1; j >= 0; j--) {
        if (s[j] != s[n - i]) {
          minSwaps = min(minSwaps, swaps[j]);
        }
      }

      // If there is no answer, then set the number of swaps to -1.
      if (minSwaps == -1) {
        swaps[i] = -1;
      } else {
        swaps[i] = minSwaps + 1;
      }
    }

    // Print the number of swaps required for each value of i.
    for (int i = 1; i <= n; i++) {
      cout << swaps[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
