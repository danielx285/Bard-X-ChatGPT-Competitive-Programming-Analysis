#include <iostream>
#include <vector>

using namespace std;

int countOddBitwiseORSubarrays(vector<int>& A, int K) {
    int oddCount = 0;
    int oddOR = 0;
    int N = A.size();
    
    for (int i = 0; i < K; i++) {
        oddOR |= A[i];
    }
    
    if (oddOR % 2 != 0) {
        oddCount++;
    }
    
    for (int i = K; i < N; i++) {
        oddOR ^= A[i - K];
        oddOR |= A[i];
        
        if (oddOR % 2 != 0) {
            oddCount++;
        }
    }
    
    return oddCount;
}

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

        int result = countOddBitwiseORSubarrays(A, K);
        cout << result << endl;
    }

    return 0;
}
