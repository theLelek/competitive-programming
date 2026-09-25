#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

string s1; string s2;

vector<vector<int>> dp;

int solveRecursively(int idx1, int idx2) {
    if (idx1 == s1.size())
        return s2.size() - idx2;

    if (idx2 == s2.size())
        return s1.size() - idx1;

    // adds before idx1
    int ans1 = 1 + solveRecursively(idx1, idx2 + 1);

    if (idx1 == s1.size() && idx2 == s2.size()) {
        return s1.at(idx1) == s2.at(idx2) ? 0 : INT_MAX / 2;
    }

    // replace
    int toAdd2 = s1.at(idx1) == s2.at(idx2) ? 0 : 1;
    int ans2 = toAdd2 + solveRecursively(idx1 + 1, idx2 + 1);

    // remove
    int ans3 = 1 + solveRecursively(idx1 + 1, idx2);

    int ans = min(ans1, min(ans2, ans3));
    return ans;
}

int main() {
    cin >> s1; cin >> s2;

    dp.resize(s1.size() + 5, vector<int>(s2.size() + 5));

    cout << solveRecursively(0, 0);
    return 0;
}