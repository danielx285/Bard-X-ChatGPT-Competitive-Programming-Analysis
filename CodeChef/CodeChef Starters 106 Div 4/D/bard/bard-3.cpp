#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Count the number of odd subarrays of length K.
        int count = 0;
        for (int i = 0; i < n; i++) {
            // Calculate the bitwise OR of the current subarray.
            int or_value = 0;
            for (int j = i; j < i + k; j++) {
                or_value |= arr[j];
            }

            // If the bitwise OR is odd, increment the count.
            if (or_value % 2 == 1) {
                count++;
            }
        }

        // Print the count.
        cout << count << endl;
    }

    return 0;
}
