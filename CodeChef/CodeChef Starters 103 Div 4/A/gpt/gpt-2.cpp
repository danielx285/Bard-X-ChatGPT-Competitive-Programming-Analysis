#include <iostream>

int main() {
    int X;
    std::cin >> X;

    if (X < 3) {
        std::cout << "GOLD" << std::endl;
    } else if (X < 6) {
        std::cout << "SILVER" << std::endl;
    } else {
        std::cout << "BRONZE" << std::endl;
    }

    return 0;
}
