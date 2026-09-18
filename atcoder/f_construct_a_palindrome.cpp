#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<char> letters;
vector<vector<int>> adjList;

struct element {
    vector<int> nodes;
    vector<int> distance;
};

int main() {
    int n; int m;
    cin >> n; cin >> m;
    adjList.resize(n + 1);
    letters.resize(n + 1);

    for (int i = 1; i <= m; i++) {
        int a; int b; char c;
        cin >> a; cin >> b; cin >> c;

        letters.at(i) = c;
        adjList.at(a).push_back(b);
        adjList.at(b).push_back(a);
    }

    vector<element> doesCharExist(26); // chars - 97

    queue<element> q = {};
    q.push(element({1}, {0}));

    return 0;
}