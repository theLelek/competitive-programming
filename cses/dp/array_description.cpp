#include <vector>
#include <iostream>

using namespace std;


vector<int> numbersInput;
int m;
vector<vector<int>> dp;

int solveRecursively(int idx, int prevValue) {
    if (idx == numbersInput.size()) {
        return 1;
    }
    if (dp.at(idx).at(prevValue) != -1) {
        return dp.at(idx).at(prevValue);
    }
    int ans = 0;

    if (numbersInput.at(idx) != 0) {
        if (abs(prevValue - numbersInput.at(idx)) > 1) {
            return 0;
        }
        ans += solveRecursively(idx + 1, numbersInput.at(idx));
        ans %= 1000000007;
        dp.at(idx).at(numbersInput.at(idx)) = ans;
        return ans;
    }

    for (int i = prevValue - 1; i <= m; i++) {
        if (i == 0 || i == -1) continue;
        if (i > prevValue + 1 && prevValue != 0) break;
        if (abs(prevValue - i) <= 1 || idx == 0 || prevValue == 0) {
            ans += solveRecursively(idx + 1, i);
            ans %= 1000000007;
        }
    }
    dp.at(idx).at(prevValue) = ans;
    return ans;
}

int main() {
    int n;
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        numbersInput.push_back(c);
    }
    dp.resize(n + 5, vector<int>(m + 5, -1));
    cout << solveRecursively(0, numbersInput.at(0));
    return 0;
}