#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int len;
        string N;
        cin >> len >> N;

        // Check if N is already divisible by 8
        for (int i = 0; i < len; i++) {
            int num = (N[i] - '0');
            if (num % 8 == 0) {
                cout << "YES\n" << num << endl;
                return 0;
            }
        }

        // Try all possible combinations of two digits
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int num = (N[i] - '0') * 10 + (N[j] - '0');
                if (num % 8 == 0) {
                    cout << "YES\n" << num << endl;
                    return 0;
                }
            }
        }

        // Try all possible combinations of three digits
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                for (int k = j + 1; k < len; k++) {
                    int num = (N[i] - '0') * 100 + (N[j] - '0') * 10 + (N[k] - '0');
                    if (num % 8 == 0) {
                        cout << "YES\n" << num << endl;
                        return 0;
                    }
                }
            }
        }

        // If no divisible number is found, print NO
        cout << "NO" << endl;
    }

    return 0;
}
