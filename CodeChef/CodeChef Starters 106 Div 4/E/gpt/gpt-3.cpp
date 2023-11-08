#include <iostream>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

string find_winner(int N) {
    if (N % 2 == 0) {
        return "Bob";
    }

    if (is_prime(N)) {
        return "Alice";
    }

    return (N % 2 == 1) ? "Alice" : "Bob";
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        string winner = find_winner(N);
        cout << winner << endl;
    }

    return 0;
}
