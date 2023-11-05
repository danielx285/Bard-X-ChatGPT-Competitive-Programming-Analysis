#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int A1, A2, A3, B1, B2, B3;
        cin >> A1 >> A2 >> A3 >> B1 >> B2 >> B3;
        
        int AliceScore = max(max(A1, A2), A3);
        int BobScore = max(max(B1, B2), B3);
        
        if (AliceScore > BobScore) {
            cout << "Alice" << endl;
        } else if (AliceScore < BobScore) {
            cout << "Bob" << endl;
        } else {
            cout << "Tie" << endl;
        }
    }
    
    return 0;
}
