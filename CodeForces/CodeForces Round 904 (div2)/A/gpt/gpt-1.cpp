#include <iostream>

int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int x, k;
        std::cin >> x >> k;

        int y = x;
        while (true) {
            if (digitSum(y) % k == 0) {
                std::cout << y << std::endl;
                break;
            }
            y++;
        }
    }

    return 0;
}
