#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A[3], B[3];

        // Read Alice's dice rolls
        for (int i = 0; i < 3; i++) {
            cin >> A[i];
        }

        // Read Bob's dice rolls
        for (int i = 0; i < 3; i++) {
            cin >> B[i];
        }

        // Sort the rolls in descending order for both players
        sort(A, A + 3, greater<int>());
        sort(B, B + 3, greater<int>());

        // Compare the maximum scores
        if (A[0] > B[0]) {
            cout << "Alice" << endl;
        } else if (A[0] < B[0]) {
            cout << "Bob" << endl;
        } else {
            cout << "Tie" << endl;
        }
    }

    return 0;
}
