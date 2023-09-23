#include <iostream>
#include <queue>

using namespace std;

bool is321Like(int n) {
  int prevDigit = n % 10;
  n /= 10;
  while (n > 0) {
    int currDigit = n % 10;
    if (currDigit >= prevDigit) {
      return false;
    }
    prevDigit = currDigit;
    n /= 10;
  }
  return true;
}

int findKthSmallest321LikeNumber(int k) {
  priority_queue<int> pq;
  int n = 1;
  while (pq.size() < k) {
    if (is321Like(n)) {
      pq.push(n);
    }
    n++;
  }

  return pq.top();
}

int main() {
  int k;
  cin >> k;

  int kthSmallest321LikeNumber = findKthSmallest321LikeNumber(k);
  cout << kthSmallest321LikeNumber << endl;

  return 0;
}
