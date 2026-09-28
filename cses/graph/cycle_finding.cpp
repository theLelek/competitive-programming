#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int n; int m;
vector<vector<int>> edgeList;
vector<int> minDistance;

void bellmanFordHelper() {
    for (vector<int> edge : edgeList) {
        int distance1 = minDistance.at(edge.at(0));
        int distance2 = minDistance.at(edge.at(1)) + edge.at(2);
        minDistance.at(edge.at(0)) = min(distance1, distance2);

        int distance3 = minDistance.at(edge.at(1));
        int distance4 = minDistance.at(edge.at(0)) + edge.at(2);
        minDistance.at(edge.at(1)) = min(distance3, distance4);
    }
}

void bellmanFord() {
    for (int i = 0; i < n - 1; i++) {
        bellmanFordHelper();
    }
}

int main() {
    cin >> n; cin >> m;
    minDistance.resize(n + 1, INT_MAX / 2);
    minDistance.at(1) = 0;

    for (int i = 0; i < m; i++) {
        int a; int b; int c;
        cin >> a; cin >> b; cin >> c;
        edgeList.push_back({a, b, c});
    }

    bellmanFord();
    return 0;
}