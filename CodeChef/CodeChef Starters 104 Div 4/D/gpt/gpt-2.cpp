#include <iostream>
#include <algorithm>

using namespace std;

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate the least common multiple (LCM)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int X, Y, K;
        cin >> X >> Y >> K;
        
        int g = gcd(X, Y);
        int l = lcm(X, Y);
        
        // If K is even, they will perform K/2 operations
        // If K is odd, Alice will perform one more operation than Bob
        int operations_by_alice = K / 2;
        int operations_by_bob = K - operations_by_alice;
        
        // Calculate the final sum
        int final_sum = g * operations_by_alice + l * operations_by_bob;
        
        cout << final_sum << endl;
    }
    
    return 0;
}
