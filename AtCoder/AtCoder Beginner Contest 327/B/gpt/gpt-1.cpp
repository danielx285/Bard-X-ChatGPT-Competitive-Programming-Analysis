#include <iostream>
#include <cmath>

int main() {
    long long B;
    std::cin >> B;

    if (B == 1) {
        // Special case: 1^1 = 1, and it's the only solution.
        std::cout << "1" << std::endl;
    } else if (B % 2 == 0) {
        // If B is even, there is no solution, because even powers of any positive integer will be even.
        std::cout << "-1" << std::endl;
    } else {
        // If B is odd, the answer is B itself because B^B = B.
        std::cout << B << std::endl;
    }

    return 0;
}
