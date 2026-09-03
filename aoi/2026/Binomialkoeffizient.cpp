#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

vector<vector<int>> dp;

long long solveIteratively(int n, int k) {
    dp.at(0).at(0) = 1;
    for (int i = 1; i <= n; i++) {
        dp.at(i).at(0) = 1;
        for (int j = 1; j <= i; j++) {
            dp.at(i).at(j) = dp.at(i - 1).at(j - 1) + dp.at(i - 1).at(j);
        }
    }
    return dp.at(n).at(k);
}

long long solveRecursively(int n, int k) {
    if (dp.at(n).at(k) != INT_MIN) {
        return dp.at(n).at(k);
    }
    if (k == 0 || k == n) {
        return 1;
    }

    long long foo = 0;
    foo += solveRecursively(n - 1, k - 1);
    foo += solveRecursively(n - 1, k);
    dp.at(n).at(k) = foo % 1000000007;
    //  % 1000000007
    return foo % 1000000007;
}

int main() {
    int n; int k; cin >> n; cin >> k;
    dp.resize(n + 5, vector<int> (k + 5, INT_MIN));

    cout << solveIteratively(n, k);
    return 0;
}