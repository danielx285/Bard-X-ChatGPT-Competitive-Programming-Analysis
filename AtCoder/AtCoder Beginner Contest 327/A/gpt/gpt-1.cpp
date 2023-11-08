#include <iostream>
#include <string>

int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    for (int i = 0; i < N - 1; ++i) {
        if (S[i] == 'a' && S[i + 1] == 'b' || S[i] == 'b' && S[i + 1] == 'a') {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }

    std::cout << "No" << std::endl;

    return 0;
}
