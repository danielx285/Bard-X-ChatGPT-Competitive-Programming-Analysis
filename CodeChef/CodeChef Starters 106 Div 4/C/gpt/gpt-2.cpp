#include <iostream>

long long int nCr(int n, int r) {
    if (r == 0 || r == n) {
        return 1;
    }
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        // The number of ways to choose a captain and a vice-captain from N players is C(N, 1) * C(N-1, 1)
        // Since there are C(N, 1) ways to choose the captain and C(N-1, 1) ways to choose the vice-captain.
        long long int choices = nCr(N, 1) * nCr(N - 1, 1);

        std::cout << choices << std::endl;
    }

    return 0;
}
