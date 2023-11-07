#include <iostream>
#include <vector>
#include <algorithm>

bool isGoodArray(const std::vector<int>& a) {
    int n = a.size();
    if (n < 2) {
        return true; // Trivially good
    }

    // Sort the array to make it easier to check
    std::vector<int> sorted_a = a;
    std::sort(sorted_a.begin(), sorted_a.end());

    // Calculate the expected sum
    int expected_sum = sorted_a[0] + sorted_a[n - 1];

    // Check if the array is good
    for (int i = 1; i < n - 1; i++) {
        if (sorted_a[i] + sorted_a[i + 1] != expected_sum) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        if (isGoodArray(a)) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }

    return 0;
}
