#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    
    vector<int> A(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    int sum = 0;
    for (int i = 0; i < N - 1; i++) {
        sum += A[i];
    }
    
    int min_score = 0;
    
    // If the current sum is already greater than or equal to X, no need to increase the score in round N.
    if (sum >= X) {
        cout << "0" << endl;
    } else {
        // Calculate the minimum score needed in round N to achieve X or higher.
        int remaining = X - sum;
        
        // If remaining is greater than 100, it's impossible to achieve X or higher.
        if (remaining > 100) {
            cout << "-1" << endl;
        } else {
            // Otherwise, the minimum score needed in round N is remaining.
            cout << remaining << endl;
        }
    }
    
    return 0;
}
