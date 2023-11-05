#include <iostream>
#include <string>
using namespace std;

// Function to check if a string is divisible by 8
bool isDivisibleBy8(string num) {
    int n = num.length();
    if (n == 1) {
        return (num[0] - '0') % 8 == 0;
    } else if (n == 2) {
        int val = (num[0] - '0') * 10 + (num[1] - '0');
        return val % 8 == 0;
    } else {
        int val = (num[n - 3] - '0') * 100 + (num[n - 2] - '0') * 10 + (num[n - 1] - '0');
        return val % 8 == 0;
    }
}

// Function to find the minimum number of changes to make a string divisible by 8
string makeDivisibleBy8(string num) {
    int n = num.length();
    
    // Check if the original number is already divisible by 8
    if (isDivisibleBy8(num)) {
        return num;
    }
    
    // Try to change one digit at a time to make it divisible by 8
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                string temp = "";
                temp += num[i];
                temp += num[j];
                temp += num[k];
                
                if (isDivisibleBy8(temp)) {
                    return temp;
                }
            }
        }
    }
    
    // If no single change makes it divisible by 8, return an empty string
    return "";
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int len;
        string N;
        cin >> len >> N;
        
        string result = makeDivisibleBy8(N);
        if (result.empty()) {
            cout << "-1" << endl; // No valid answer
        } else {
            cout << result << endl;
        }
    }
    
    return 0;
}
