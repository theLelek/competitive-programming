#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> numbersInput;
// vector<vector<int>> dp;
//
// int solveRecursively(int idx, int minValue) {
//     if (idx == n) {
//         return 0;
//     }
//
//     int ans1 = solveRecursively(idx + 1, minValue);
//     int ans2 = INT_MIN;
//     if (numbersInput.at(idx) >= minValue) {
//         ans2 = 1 + solveRecursively(idx + 1, numbersInput.at(idx) + 1);
//     }
//     return max(ans1, ans2);
// }

vector<int> dp;

int solveIteratively() {
    dp.resize(n + 5, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (numbersInput.at(j) < numbersInput.at(i)) {
                dp.at(i) = max(dp.at(i), dp.at(j) + 1);
            }
        }
    }
    return dp.at(n - 1);
}

int main() {
    cin >> n;
//    dp.resize(n + 5, vector<int>(1000));
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbersInput.push_back(c);
    }

    cout << solveIteratively();

    return 0;
}