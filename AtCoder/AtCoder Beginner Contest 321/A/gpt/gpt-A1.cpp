#include <iostream>

int main() {
    int N;
    std::cin >> N;

    bool is_321_like = true;
    int last_digit = N % 10;
    N /= 10;

    while (N > 0) {
        int current_digit = N % 10;
        if (current_digit <= last_digit) {
            is_321_like = false;
            break;
        }
        last_digit = current_digit;
        N /= 10;
    }

    if (is_321_like) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
