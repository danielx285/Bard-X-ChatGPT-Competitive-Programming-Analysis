#include <iostream>
#include <string>

using namespace std;

bool isDivisibleBy8(const string &s) {
    int n = s.length();
    if (n < 3) {
        int num = stoi(s);
        return num % 8 == 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
                if (num % 8 == 0) {
                    cout << "YES" << endl;
                    cout << num << endl;
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int len;
        string N;
        cin >> len >> N;

        if (isDivisibleBy8(N)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < len; i++) {
                for (int j = i + 1; j < len; j++) {
                    for (int k = j + 1; k < len; k++) {
                        int num = (N[i] - '0') * 100 + (N[j] - '0') * 10 + (N[k] - '0');
                        if (num % 8 == 0) {
                            cout << num << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}
