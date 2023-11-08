#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(M);
    vector<int> B(M);

    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    vector<int> X(N, 0); // Initialize X with all 0s

    for (int i = 0; i < M; i++) {
        if (X[A[i] - 1] == 1 || X[B[i] - 1] == 1) {
            cout << "No" << endl;
            return 0;
        }
        X[A[i] - 1] = 1;
        X[B[i] - 1] = 1;
    }

    cout << "Yes" << endl;

    return 0;
}
