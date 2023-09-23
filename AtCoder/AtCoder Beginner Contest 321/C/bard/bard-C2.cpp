#include <iostream>
#include <queue>

using namespace std;

int main() {
  int K;
  cin >> K;

  priority_queue<int> pq;

  // Add all one-digit positive integers to the priority queue.
  for (int i = 1; i <= 9; i++) {
    pq.push(i);
  }

  // While the priority queue is not empty, pop the largest element and check if it is 321-like.
  // If it is, add it to the result list.
  while (!pq.empty()) {
    int current_number = pq.top();
    pq.pop();

    // Check if the current number is 321-like.
    bool is_321_like = true;
    int previous_digit = -1;
    while (current_number > 0) {
      int current_digit = current_number % 10;
      current_number /= 10;

      if (current_digit >= previous_digit) {
        is_321_like = false;
        break;
      }

      previous_digit = current_digit;
    }

    if (is_321_like) {
      // The current number is 321-like. Add it to the result list.
      if (--K == 0) {
        cout << current_number << endl;
        return 0;
      }
    }

    // Generate the next possible 321-like number.
    for (int i = current_number % 10 - 1; i >= 0; i--) {
      int next_number = current_number * 10 + i;
      pq.push(next_number);
    }
  }

  // If the priority queue is empty, then there are not enough 321-like numbers.
  cout << "-1" << endl;
  return 0;
}
