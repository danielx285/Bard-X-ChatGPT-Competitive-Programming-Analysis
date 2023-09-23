#include <iostream>
#include <string>

using namespace std;

int main() {
    string N;
    cin >> N;
    
    bool is_321_like = true;
    
    for (int i = 1; i < N.length(); ++i) {
        if (N[i - 1] <= N[i]) {
            is_321_like = false;
            break;
        }
    }
    
    if (is_321_like) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
