#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;

        if (N % 2 == 0) {
            cout << "Bob" << endl;
        } else if (isPrime(N)) {
            cout << "Alice" << endl;
        } else {
            int cnt = 0;
            while (N % 2 == 0) {
                N /= 2;
                cnt++;
            }

            if (cnt == 1) {
                cout << "Bob" << endl;
            } else {
                cout << "Alice" << endl;
            }
        }
    }

    return 0;
}
