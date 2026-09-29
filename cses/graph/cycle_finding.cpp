#include <deque>
#include <iostream>
#include <vector>

using namespace std;

struct element {
    long long minDistance;
    long long previousNode;

    bool operator==(const element &other) const {
        return minDistance == other.minDistance
        && previousNode == other.previousNode;
    }
};

long long n; long long m;
vector<vector<long long>> edgeList;
vector<element> minDistance;

void bellmanFord() {
    for (vector<long long> edge : edgeList) {
        long long distance1 = minDistance.at(edge.at(1)).minDistance;
        long long distance2 = minDistance.at(edge.at(0)).minDistance + edge.at(2);

        if (distance2 < distance1) {
            minDistance.at(edge.at(1)) = {distance2, edge.at(0)};
        }
    }
}

void printCycle(long long differenceIndex) {
    long long cycleStart = differenceIndex;
    for (long long i = 0; i < n + 5; i++) {
        cycleStart = minDistance.at(cycleStart).previousNode;
    }

    deque<long long> toPrint;
    vector<bool> visited(n + 1);
    long long current = cycleStart;

    while (! visited.at(current)) {
        toPrint.push_front(current);
        visited.at(current) = true;
        current = minDistance.at(current).previousNode;
    }
    cout << cycleStart << " ";
    for (long long e : toPrint) {
        cout << e << " ";
    }
}

int main() {
    cin >> n; cin >> m;
    minDistance.resize(n + 1, {0, -1});

    for (long long i = 0; i < m; i++) {
        long long a; long long b; long long c;
        cin >> a; cin >> b; cin >> c;
        edgeList.push_back({a, b, c});
    }

    for (long long i = 0; i < n - 1; i++) {
        bellmanFord();
    }
    vector<element> minDistanceCopy = minDistance;
    bellmanFord();

    for (long long i = 0; i < minDistance.size(); i++) {
        if (! (minDistance.at(i) == minDistanceCopy.at(i))) {
            cout << "YES" << "\n";
            printCycle(i);
            return 0;
        }
    }
    cout << "NO";
    return 0;
}