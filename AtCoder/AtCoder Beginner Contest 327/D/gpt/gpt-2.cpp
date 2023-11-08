#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> A(M);
    vector<int> B(M);
    vector<int> X(N, 0);

    for (int i = 0; i < M; i++) {
        cin >> A[i];
        X[A[i] - 1] = 1;
    }

    for (int i = 0; i < M; i++) {
        cin >> B[i];
        X[B[i] - 1] = 1;
    }

    for (int i = 0; i < M; i++) {
        if (X[A[i] - 1] == 1 && X[B[i] - 1] == 1) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
