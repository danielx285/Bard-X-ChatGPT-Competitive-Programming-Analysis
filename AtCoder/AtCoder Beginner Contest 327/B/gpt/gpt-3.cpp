#include <iostream>
#include <cmath>

using namespace std;

bool check(long long B, long long A) {
    // Check if A^A equals B
    long long result = 1;
    for (int i = 0; i < A; i++) {
        result *= A;
        if (result > B) {
            return false;
        }
    }
    return result == B;
}

long long findA(long long B) {
    long long left = 1, right = B;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (check(B, mid)) {
            return mid;
        }
        if (mid * mid < B) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    long long B;
    cin >> B;
    
    long long A = findA(B);
    
    if (A == -1) {
        cout << -1 << endl;
    } else {
        cout << A << endl;
    }
    
    return 0;
}
