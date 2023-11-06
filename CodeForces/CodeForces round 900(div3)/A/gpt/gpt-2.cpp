#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int maxCount = 0; // Maximum count of the element k
        unordered_map<int, int> count; // Count of each element in the current subsegment

        int left = 0; // Left pointer of the subsegment
        bool found = false; // Flag to check if a subsegment with k as the most common element is found

        for (int right = 0; right < n; right++) {
            count[a[right]]++; // Increment count for the current element

            if (count[k] > maxCount) {
                maxCount = count[k]; // Update maxCount if k appears more times than any other element
            }

            // Check if the current subsegment is valid (contains k as the most common element)
            while (right - left + 1 - maxCount > 1) {
                count[a[left]]--; // Shrink the subsegment from the left
                left++;
            }

            // If k is the most common element in the current subsegment, set the found flag
            if (right - left + 1 == maxCount) {
                found = true;
                break; // No need to continue checking
            }
        }

        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
