#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> ans(n + 1, vector<int>(n + 1, -1));

    // Calculate the answer for i = 1
    for (int i = 0; i <= n; i++) {
      if (s[i] == '1') {
        ans[i][1] = 0;
      }
    }

    // Calculate the answer for i > 1
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        if (ans[j][i - 1] != -1) {
          // If we can divide the number by 2^(i - 1),
          // we can also divide it by 2^i by swapping the
          // first two bits.
          if (j % 2 == 0) {
            ans[j][i] = ans[j][i - 1] + 1;
          }

          // If the number is not divisible by 2^(i - 1),
          // we can try to make it divisible by 2^i by swapping
          // the first two bits and the last two bits.
          if (j % 2 == 1 && j + 1 <= n) {
            if (s[j] == '0' && s[j + 1] == '1') {
              ans[j][i] = ans[j][i - 1] + 1;
            }
          }
        }
      }
    }

    // Print the answer
    for (int i = 1; i <= n; i++) {
      cout << ans[n][i] << " ";
    }
    cout << endl;
  }

  return 0;
}
