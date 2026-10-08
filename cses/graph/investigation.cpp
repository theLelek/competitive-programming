#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

struct element {
    int node;
    int weight;
};

struct qElement {
    int node;
    long long dist;
    long long amountOfFlights;

    bool operator<(const qElement& other) const {
        return dist < other.dist;
    }
};

int n; int m;
vector<vector<element>> adjacencyList;

vector<long long> dist;
vector<long long> amountOfRoutes;
vector<long long> minNumberOfFlights;
vector<long long> maxNumberOfFlights;

void dijkstra() {
    priority_queue<qElement> queue;
    queue.push({1, 0, 0});
    while (queue.size() > 0) {
        qElement current = queue.top();
        queue.pop();
        if (current.dist > dist.at(current.node)) continue;

        if (dist.at(current.node) == current.dist) {
            amountOfRoutes.at(current.node)++;
            amountOfRoutes.at(current.node) %= 1000000007;
            minNumberOfFlights.at(current.node) = min(minNumberOfFlights.at(current.node), current.amountOfFlights);
            maxNumberOfFlights.at(current.node) = max(maxNumberOfFlights.at(current.node), current.amountOfFlights);
            continue;
        }

        dist.at(current.node) = current.dist;
        amountOfRoutes.at(current.node) = 1;
        minNumberOfFlights.at(current.node) = current.amountOfFlights;
        maxNumberOfFlights.at(current.node) = current.amountOfFlights;

        for (element node : adjacencyList.at(current.node)) {
            if (dist.at(node.node) < node.weight + current.dist) continue;

            qElement currentQElement = {node.node, current.dist + node.weight, current.amountOfFlights + 1};
            queue.push(currentQElement);
        }
    }
}

int main() {
    cin >> n; cin >> m;

    adjacencyList.resize(n + 1, {});
    dist.resize(n + 1, LONG_LONG_MAX);
    amountOfRoutes.resize(n + 1);
    minNumberOfFlights.resize(n + 1, LONG_LONG_MAX);
    maxNumberOfFlights.resize(n + 1, LONG_LONG_MIN);

    for (int i = 0; i < m; i++) {
        int a; int b; int c;
        cin >> a; cin >> b; cin >> c;
        adjacencyList.at(a).push_back({b, c});
    }

    dijkstra();

    cout << dist.at(n) << " ";
    cout << amountOfRoutes.at(n) << " ";
    cout << minNumberOfFlights.at(n) << " ";
    cout << maxNumberOfFlights.at(n) << " ";
    return 0;
}