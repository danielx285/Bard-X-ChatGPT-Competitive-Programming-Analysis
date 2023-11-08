#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 5;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(m), b(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
  }

  // Create a hash table to store the values of XSi and XTi.
  unordered_map<int, int> hash_table;
  for (int i = 0; i < m; i++) {
    hash_table[a[i]] = 0;
    hash_table[b[i]] = 1;
  }

  // Check if there exists a sequence X that satisfies the condition.
  bool is_good_pair = true;
  for (int i = 0; i < m; i++) {
    if (hash_table[a[i]] == hash_table[b[i]]) {
      is_good_pair = false;
      break;
    }
  }

  // Print the output.
  if (is_good_pair) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
