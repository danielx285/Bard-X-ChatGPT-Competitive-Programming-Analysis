#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        sort(A.begin(), A.end());  // Sort the array in ascending order.

        int min_chocolates = A[0] + K;  // Minimum chocolates for the first child.
        int max_chocolates = A[N - 1] - K;  // Maximum chocolates for the last child.

        // Check if the difference between minimum and maximum chocolates is less than or equal to 2*K.
        if (max_chocolates >= min_chocolates) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
