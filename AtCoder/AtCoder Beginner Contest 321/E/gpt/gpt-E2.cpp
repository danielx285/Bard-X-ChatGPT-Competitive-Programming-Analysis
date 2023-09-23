#include <iostream>
#include <vector>

using namespace std;

// Function to count the number of vertices at distance K from vertex X
long long countVertices(long long N, long long X, long long K) {
    long long count = 0;
    while (X > 0 && K >= 0) {
        if (K == 0) {
            count++;
            break;
        }
        long long odd = (X % 2 == 1);
        long long numNodes = X / 2 + odd;
        if (K >= numNodes) {
            break;
        }
        X = X / 2;
        K--;
        count++;
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long N, X, K;
        cin >> N >> X >> K;
        long long result = countVertices(N, X, K);
        cout << result << endl;
    }
    return 0;
}
