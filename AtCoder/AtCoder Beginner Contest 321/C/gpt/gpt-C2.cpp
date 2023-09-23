#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int findKth321LikeNumber(int K) {
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap to store 321-like numbers
    
    for (int i = 0; i <= 9; ++i) {
        pq.push(i);
    }
    
    int count = 0;
    int result = 0;
    
    while (count < K) {
        int current = pq.top();
        pq.pop();
        
        result = current;
        ++count;
        
        int last_digit = current % 10;
        for (int i = 0; i < last_digit; ++i) {
            int new_number = current * 10 + i;
            pq.push(new_number);
        }
    }
    
    return result;
}

int main() {
    int K;
    cin >> K;

    int result = findKth321LikeNumber(K);

    cout << result << endl;

    return 0;
}
