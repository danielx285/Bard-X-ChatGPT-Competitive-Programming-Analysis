#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, X, D;
        cin >> N >> X >> D;

        int total_buns_needed = X * D;
        int days_survived = 0;

        if (total_buns_needed <= N) {
            days_survived = D;
        } else {
            int days_without_food = N / X;
            days_survived = days_without_food + D;
        }

        cout << days_survived << endl;
    }

    return 0;
}
