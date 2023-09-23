#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    
    vector<int> A(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    int min_score = 0;
    for (int i = 0; i < N - 1; i++) {
        min_score += A[i];
    }
    
    int max_score = A[N - 2];
    int remaining_score = X - min_score;
    
    if (remaining_score <= 0) {
        cout << 0 << endl;
    } else if (remaining_score <= 100) {
        cout << remaining_score << endl;
    } else if (remaining_score <= max_score) {
        cout << remaining_score << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
