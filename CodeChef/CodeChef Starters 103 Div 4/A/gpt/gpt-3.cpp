#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;

    if (X < 3) {
        cout << "GOLD" << endl;
    } else if (X < 6) {
        cout << "SILVER" << endl;
    } else {
        cout << "BRONZE" << endl;
    }

    return 0;
}
