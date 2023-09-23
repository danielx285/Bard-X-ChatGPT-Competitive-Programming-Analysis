#include <iostream>
using namespace std;

int findKth321Like(int K) {
    int current = 1; // Start with the smallest 321-like number
    int count = 1;

    while (count < K) {
        // Generate the next 321-like number
        int temp = current;
        while (true) {
            temp++;
            bool is_321_like = true;
            int digit = 10;
            int prev_digit = temp % 10;
            temp /= 10;

            while (temp > 0) {
                digit = temp % 10;
                if (digit <= prev_digit) {
                    is_321_like = false;
                    break;
                }
                prev_digit = digit;
                temp /= 10;
            }

            if (is_321_like) {
                current = current * 10 + digit;
                break;
            }
        }
        count++;
    }

    return current;
}

int main() {
    int K;
    cin >> K;

    int result = findKth321Like(K);

    cout << result << endl;

    return 0;
}
