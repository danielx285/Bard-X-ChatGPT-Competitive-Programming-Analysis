#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, P;
    cin >> N >> M >> P;
    
    vector<long long> A(N);
    vector<long long> B(M);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    long long total_price = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            long long s = A[i] + B[j];
            total_price += min(s, (long long)P);
        }
    }
    
    cout << total_price << endl;
    
    return 0;
}
