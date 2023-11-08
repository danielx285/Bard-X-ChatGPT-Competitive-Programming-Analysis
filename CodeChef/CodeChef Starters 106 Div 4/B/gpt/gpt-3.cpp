#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, X, D;
        cin >> N >> X >> D;

        int dailyRequirement = X * 5; // Total requirement for the family per day

        if (N >= dailyRequirement) {
            // There are enough buns for the family
            int remainingDays = N / dailyRequirement;
            int totalDays = remainingDays + min(remainingDays, D);
            cout << totalDays << endl;
        } else {
            // Not enough buns for the family
            int totalDays = min(N / dailyRequirement, D);
            cout << totalDays << endl;
        }
    }

    return 0;
}
