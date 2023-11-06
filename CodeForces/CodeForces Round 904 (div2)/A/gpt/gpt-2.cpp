#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int x, k;
        cin >> x >> k;

        int y = x;
        while (true) {
            int sum = 0;
            int num = y;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            
            if (sum % k == 0) {
                cout << y << endl;
                break;
            }
            
            y++;
        }
    }
    
    return 0;
}
