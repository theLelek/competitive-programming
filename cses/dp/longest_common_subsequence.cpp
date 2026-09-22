#include <iostream>
#include <vector>

using namespace std;

int n; int m;
vector<int> numbers1;
vector<int> numbers2;

vector<vector<pair<int, vector<int>>>> dp;

int solveRecursively(int idx1, int idx2) { // will use too much memory on one of the inputs
    if (idx1 == numbers1.size() || idx2 == numbers2.size()) {
        return 0;
    }
    if (dp.at(idx1).at(idx2).first != -1) {
        return dp.at(idx1).at(idx2).first;
    }

    int ansLength;
    vector<int> ansList;

    if (numbers1.at(idx1) == numbers2.at(idx2)) {
        ansLength = 1 + solveRecursively(idx1 + 1, idx2 + 1);
        ansList = dp.at(idx1 + 1).at(idx2 + 1).second;
        ansList.push_back(numbers1.at(idx1));
    } else {
        int ans1Length = solveRecursively(idx1 + 1, idx2);
        int ans2Length = solveRecursively(idx1, idx2 + 1);

        if (ans1Length > ans2Length) {
            ansLength = ans1Length;
            ansList = dp.at(idx1 + 1).at(idx2).second;
        } else {
            ansLength = ans2Length;
            ansList = dp.at(idx1).at(idx2 + 1).second;
        }
    }

    dp.at(idx1).at(idx2) = {ansLength, ansList};
    return ansLength;
}

pair<int, vector<int>> solveIteratively() {
    vector<pair<int, vector<int>>> dpPrevious;
    vector<pair<int, vector<int>>> dpCurrent(numbers2.size());
    for (int i = 0; i < numbers1.size(); i++) {
        fill(dpCurrent.begin(), dpCurrent.end(), pair<int, vector<int>>(0, {}));

        for (int j = 0; j < numbers2.size(); j++) { // todo what if a pair exists multiple times
            if (numbers1.at(i) == numbers2.at(j)) {
                int toAdd = i == 0 || j == 0 ? 0 : dpPrevious.at(j - 1).first;
                dpCurrent.at(j).first = 1 + toAdd;
            } else {
                int ans1 = i == 0 ? 0 : dpPrevious.at(j).first;
                int ans2 = j == 0 ? 0 : dpCurrent.at(j - 1).first;
                dp.at(i).at(j).first = max(ans1, ans2);
            }
        }
        dpPrevious = dpCurrent;
    }
    return {dpCurrent.at(m - 1).first, {}};
}

int main() {
    cin >> n; cin >> m;
    dp.resize(n + 5, vector<pair<int, vector<int>>>(m + 5, {-1, {}}));


    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbers1.push_back(c);
    }
    for (int i = 0; i < m; i++) {
        int c; cin >> c;
        numbers2.push_back(c);
    }

    // int ans = solveRecursively(0, 0);
    // cout << ans << "\n";
    // for (int i = dp.at(0).at(0).second.size() - 1; i >= 0; i--) {
    //     if (dp.at(0).at(0).second.size() == 0) break;
    //     cout << dp.at(0).at(0).second.at(i) << " ";
    // }

    pair<int, vector<int>> ans = solveIteratively();
    cout << ans.first << "\n";

    for (int element : ans.second) {
        cout << element << " ";
    }
    return 0;
}