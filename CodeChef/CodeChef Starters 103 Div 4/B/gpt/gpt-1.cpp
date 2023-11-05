#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int X, Y;
        cin >> X >> Y;
        
        int max_neighbours = X / Y;
        cout << max_neighbours << endl;
    }
    
    return 0;
}
