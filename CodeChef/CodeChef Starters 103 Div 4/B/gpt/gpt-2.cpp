#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int X, Y;
        cin >> X >> Y;

        int max_neighbors_fed = X / Y;
        cout << max_neighbors_fed << endl;
    }

    return 0;
}
