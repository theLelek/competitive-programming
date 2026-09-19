#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<char> letters;
vector<vector<int>> adjList;

struct node {
    int index;
    int distance;
};

struct element {
    vector<node> nodes;
};

queue<node> qLeft;
queue<node> qRight;
vector<element> doesCharExistLeft(26); // chars - 97

void bfsLeft() {
    while (! qLeft.empty()) {
        node current = qLeft.front();
        qLeft.pop();
        for (int child : adjList.at(current.index)) {
            char letter = letters.at(child);
            doesCharExistLeft.at((int) letter - 97).nodes.push_back({child, current.distance + 1});
        }
    }
}

void bfsRight() {
    vector<bool> alreadyAdded(26);
    queue<node> qRight2;
    while (! qRight.empty()) {
        node current = qRight.front();
        qRight.pop();
        for (int child : adjList.at(current.index)) {
            char letter = letters.at(child);
            if (doesCharExistLeft.at((int) letter - 97).nodes.empty()) {
                continue;
            }
            qRight2.push({child, current.distance + 1});
            if (alreadyAdded.at((int) letter - 97)) {
                continue;
            }
            for (node n : doesCharExistLeft.at((int) letter - 97).nodes) {
                qLeft.push(n);
            }
            alreadyAdded.at((int) letter - 97) = true;
        }
    }
    qRight = qRight2;
}

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

    qLeft.push({1, 0});
    qRight.push({n, 0});
    bfsLeft();
    bfsRight();

    return 0;
}