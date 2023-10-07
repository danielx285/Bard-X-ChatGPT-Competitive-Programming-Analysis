#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// A struct to represent a range of indices in a string.
struct Range {
  int start;
  int end;
};

// Reverses the substring of the given string from the given start index to the given end index.
void ReverseSubstring(string& s, int start, int end) {
  reverse(s.begin() + start, s.begin() + end + 1);
}

// Modifies the given string according to the given modification.
void ModifyString(string& s, const Range& range, int x) {
  // Find the index of the substring to be reversed.
  int i = 0;
  while (i < range.end - range.start && range.start + i < x) {
    i++;
  }

  // Find the start and end indices of the substring to be reversed.
  int a = min(x, range.end - i);
  int b = max(x, range.end - i);

  // Reverse the substring.
  ReverseSubstring(s, a, b);
}

int main() {
  // Read the number of test cases.
  int t;
  cin >> t;

  // Iterate over the test cases.
  while (t--) {
    // Read the length of the string and the number of modifications.
    int n, q;
    cin >> n >> q;

    // Read the string.
    string s;
    cin >> s;

    // Read the range of indices for each modification.
    vector<Range> ranges(q);
    for (int i = 0; i < q; i++) {
      cin >> ranges[i].start >> ranges[i].end;
    }

    // Read the indices to be modified.
    vector<int> modification_indices(q);
    for (int i = 0; i < q; i++) {
      cin >> modification_indices[i];
    }

    // Apply the modifications to the string.
    for (int i = 0; i < q; i++) {
      ModifyString(s, ranges[i], modification_indices[i]);
    }

    // Print the modified string.
    cout << s << endl;
  }

  return 0;
}
