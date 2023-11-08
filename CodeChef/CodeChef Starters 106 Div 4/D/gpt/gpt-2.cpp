#include <iostream>
#include <vector>

using namespace std;

int countSubarraysWithOddOR(vector<int>& A, int K) {
    int oddCount = 0;
    int prefixOR = 0;
    
    for (int i = 0; i < K; i++) {
        prefixOR |= A[i];
    }
    
    if (prefixOR % 2 == 1) {
        oddCount++;
    }
    
    for (int i = K; i < A.size(); i++) {
        prefixOR |= A[i];
        prefixOR ^= A[i - K];
        
        if (prefixOR % 2 == 1) {
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
        
        int result = countSubarraysWithOddOR(A, K);
        cout << result << endl;
    }
    
    return 0;
}
