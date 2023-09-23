#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, P;
    cin >> N >> M >> P;

    vector<long long> A(N);
    vector<long long> B(M);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    // Sort the dishes in non-decreasing order.
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long total_price = 0;

    // Iterate through all possible combinations of main and side dishes.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            long long set_meal_price = A[i] + B[j];
            long long discounted_price = min(set_meal_price, (long long)P);
            total_price += discounted_price;
        }
    }

    cout << total_price << endl;

    return 0;
}
