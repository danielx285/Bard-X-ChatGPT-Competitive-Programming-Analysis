#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, X, D;
        cin >> N >> X >> D;

        int days_survived = 0;
        int daily_requirement = X * 5;

        if (N >= daily_requirement) {
            // If there are enough buns to feed the family every day
            days_survived = N / daily_requirement;
            N -= days_survived * daily_requirement;
        }

        if (N >= X) {
            // If there are still some buns left after daily feeding
            int extra_days = N / X;
            days_survived += extra_days;
        }

        days_survived += D;
        cout << days_survived << endl;
    }

    return 0;
}
