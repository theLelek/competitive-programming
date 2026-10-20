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

    bool operator<(const qElement& other) const {
        return dist > other.dist;
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
    queue.push({1, 0});
    while (queue.size() > 0) {
        qElement current = queue.top();
        queue.pop();
        if (current.dist > dist.at(current.node)) continue;

        for (element node : adjacencyList.at(current.node)) {
            if (dist.at(node.node) < node.weight + current.dist) continue;

            if (dist.at(node.node) == current.dist + node.weight) {
                amountOfRoutes.at(node.node)++;
                amountOfRoutes.at(node.node) %= 1000000007;
                minNumberOfFlights.at(node.node) = min(minNumberOfFlights.at(node.node), 1 + minNumberOfFlights.at(current.node));
                maxNumberOfFlights.at(node.node) = max(maxNumberOfFlights.at(node.node), 1 + maxNumberOfFlights.at(current.node));
                continue;
            }
            dist.at(node.node) = current.dist + node.weight;
            amountOfRoutes.at(node.node) = 1;
            minNumberOfFlights.at(node.node) = min(minNumberOfFlights.at(node.node), 1 + minNumberOfFlights.at(current.node));
            maxNumberOfFlights.at(node.node) = max(maxNumberOfFlights.at(node.node), 1 + maxNumberOfFlights.at(current.node));

            qElement currentQElement = {node.node, current.dist + node.weight};
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