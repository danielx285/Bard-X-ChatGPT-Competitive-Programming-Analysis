#include <iostream>
#include <string>

using namespace std;

int main() {
    string N;
    cin >> N;

    bool is_321_like = true;
    char prev_digit = N[0];

    for (int i = 1; i < N.length(); ++i) {
        if (N[i] >= prev_digit) {
            is_321_like = false;
            break;
        }
        prev_digit = N[i];
    }

    if (is_321_like) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
