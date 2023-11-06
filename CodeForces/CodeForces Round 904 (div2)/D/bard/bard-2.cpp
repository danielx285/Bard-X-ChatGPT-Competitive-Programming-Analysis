#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    // Create a map to store the frequency of each element in the array.
    map<ll, int> freq;
    for (int i = 0; i < n; i++) {
      freq[a[i]]++;
    }

    // Count the number of good pairs.
    ll count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        // Check if there exists an integer k such that ai is divisible by ak and aj is divisible by ak at the same time.
        bool divisible = false;
        for (auto it = freq.begin(); it != freq.end(); it++) {
          if (a[i] % it->first == 0 && a[j] % it->first == 0) {
            divisible = true;
            break;
          }
        }

        // If there is no such integer k, then the pair (i, j) is good.
        if (!divisible) {
          count++;
        }
      }
    }

    cout << count << endl;
  }
  return 0;
}
