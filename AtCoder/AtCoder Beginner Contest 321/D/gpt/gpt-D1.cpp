#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, P;
    cin >> N >> M >> P;
    
    vector<long long> A(N), B(M);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    long long ans = 0;
    
    for (int i = 0; i < N; i++) {
        int idx = upper_bound(B.begin(), B.end(), P - A[i]) - B.begin();
        ans += (long long)idx * A[i] + (long long)(N - idx) * P;
    }
    
    cout << ans << endl;
    
    return 0;
}
