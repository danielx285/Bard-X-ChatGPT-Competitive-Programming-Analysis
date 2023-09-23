#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> scores(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        cin >> scores[i];
    }

    sort(scores.begin(), scores.end());

    int sum = 0;
    for (int i = 0; i < N - 2; ++i) {
        sum += scores[i];
    }

    int min_score = 0;
    if (sum >= X) {
        min_score = max(0, X - sum);
    } else {
        min_score = max(0, X - sum + scores[N - 2]);
    }

    if (min_score > 100) {
        cout << -1 << endl;
    } else {
        cout << min_score << endl;
    }

    return 0;
}
