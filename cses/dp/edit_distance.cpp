#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

string s1; string s2;

// vector<vector<int>> dp;
//
// int solveRecursively(int idx1, int idx2) {
//     if (idx1 == s1.size())
//         return s2.size() - idx2;
//     if (idx2 == s2.size())
//         return s1.size() - idx1;
//     if (dp.at(idx1).at(idx2) != -1) {
//         return dp.at(idx1).at(idx2);
//     }
//
//     // adds before idx1
//     int ans1 = 1 + solveRecursively(idx1, idx2 + 1);
//
//     if (idx1 == s1.size() && idx2 == s2.size()) {
//         return s1.at(idx1) == s2.at(idx2) ? 0 : INT_MAX / 2;
//     }
//
//     // replace
//     int toAdd2 = s1.at(idx1) == s2.at(idx2) ? 0 : 1;
//     int ans2 = toAdd2 + solveRecursively(idx1 + 1, idx2 + 1);
//
//     // remove
//     int ans3 = 1 + solveRecursively(idx1 + 1, idx2);
//
//     int ans = min(ans1, min(ans2, ans3));
//     dp.at(idx1).at(idx2) = ans;
//     return ans;
// }

int solveIteratively() {
    vector<vector<int>> dp(s1.size() + 5, vector<int>(s2.size() + 5));
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            int ans1 = 1 + dp.at(i).at(j - 1); // adds before i

            int toAdd2 = s1.at(i - 1) == s2.at(j - 1) ? 0 : 1;
            int ans2 = toAdd2 + dp.at(i - 1).at(j - 1); // replace

            int ans3 = 1 + dp.at(i - 1).at(j); // remove

            int ans = min(ans1, min(ans2, ans3));
            dp.at(i).at(j) = ans;
        }
    }
    return dp.at(s1.size()).at(s2.size());
}

int main() {
    cin >> s1; cin >> s2;

//    dp.resize(s1.size() + 5, vector<int>(s2.size() + 5, -1));
//    cout << solveRecursively(0, 0);
    cout << solveIteratively();
    return 0;
}