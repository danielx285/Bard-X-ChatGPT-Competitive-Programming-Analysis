#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;
        
        int g = gcd(x, y);
        int l = lcm(x, y);
        
        if (k % 2 == 0) {
            // If the number of operations is even, both players can try to maintain the numbers
            int minNum = min(x, y);
            int maxNum = max(x, y);
            int newMin = min(minNum, g);
            int newMax = max(maxNum, l);
            int diff = maxNum - minNum;

            // Calculate the final sum
            int finalSum = newMin + (k / 2) * diff + newMax;

            cout << finalSum << endl;
        } else {
            // If the number of operations is odd, both players have to make the numbers equal
            cout << g << endl;
        }
    }
    
    return 0;
}
