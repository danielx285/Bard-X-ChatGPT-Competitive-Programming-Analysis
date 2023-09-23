#include <iostream>
#include <vector>

int findKth321LikeNumber(int K) {
    std::vector<int> candidates;
    
    for (int i = 1; i <= 9; ++i) {
        for (int j = i + 1; j <= 9; ++j) {
            for (int k = j + 1; k <= 9; ++k) {
                int number = i * 100 + j * 10 + k;
                candidates.push_back(number);
            }
        }
    }
    
    return candidates[K-1];
}

int main() {
    int K;
    std::cin >> K;

    int result = findKth321LikeNumber(K);
    std::cout << result << std::endl;

    return 0;
}
