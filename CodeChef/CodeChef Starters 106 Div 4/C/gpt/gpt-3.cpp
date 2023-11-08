#include <iostream>

using namespace std;

// Function to calculate the number of ways to choose captain and vice-captain
long long countCaptainViceCaptainChoices(int N) {
    // The number of choices for captain is N
    // The number of choices for vice-captain is (N-1), as it should be different from the captain
    return N * (N - 1);
}

int main() {
    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int N;
        cin >> N; // Number of players Chef is considering
        long long choices = countCaptainViceCaptainChoices(N);
        cout << choices << endl;
    }

    return 0;
}
