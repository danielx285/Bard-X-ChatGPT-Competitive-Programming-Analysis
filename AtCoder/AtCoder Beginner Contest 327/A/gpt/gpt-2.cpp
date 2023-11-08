#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // Iterate through the string and check if adjacent characters are 'a' and 'b'
    for (int i = 0; i < N - 1; i++) {
        if ((S[i] == 'a' && S[i + 1] == 'b') || (S[i] == 'b' && S[i + 1] == 'a')) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
