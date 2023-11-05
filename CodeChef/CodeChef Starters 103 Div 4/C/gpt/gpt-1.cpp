#include <iostream>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int Alice[3], Bob[3];
        for (int i = 0; i < 3; i++) {
            std::cin >> Alice[i];
        }
        for (int i = 0; i < 3; i++) {
            std::cin >> Bob[i];
        }

        int AliceMax = std::max({Alice[0], Alice[1], Alice[2]});
        int BobMax = std::max({Bob[0], Bob[1], Bob[2]});

        if (AliceMax > BobMax) {
            std::cout << "Alice" << std::endl;
        } else if (AliceMax < BobMax) {
            std::cout << "Bob" << std::endl;
        } else {
            std::cout << "Tie" << std::endl;
        }
    }

    return 0;
}
