#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int X, Y;
        cin >> X >> Y;

        int max_neighbours = X / Y;
        if (max_neighbours > 20) {
            max_neighbours = 20;
        }

        cout << max_neighbours << endl;
    }

    return 0;
}
