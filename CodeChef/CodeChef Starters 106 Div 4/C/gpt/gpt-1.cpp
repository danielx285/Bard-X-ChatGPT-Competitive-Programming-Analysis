#include <iostream>

// Function to calculate the number of ways to choose captain and vice-captain
long long calculateChoices(int N) {
    // Total choices = N * (N-1)
    return static_cast<long long>(N) * (N - 1);
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        // Calculate and print the number of choices for captain and vice-captain
        long long choices = calculateChoices(N);
        std::cout << choices << std::endl;
    }

    return 0;
}
