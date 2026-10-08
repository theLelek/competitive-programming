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
    int dist;
    int amountOfFlights;

    bool operator<(const qElement& other) const {
        return dist < other.dist;
    }
};

int n; int m;
vector<vector<element>> adjacencyList;
vector<int> dist;

int outMinPrice;
int outAmount;
int outMinFlights = INT_MAX;
int outMaxFlights = INT_MIN;

void dijkstra() {
    priority_queue<qElement> queue;
    queue.push({1, 0, 0});
    while (queue.size() > 0) {
        qElement current = queue.top();
        queue.pop();
        if (dist.at(current.node) < current.dist) continue;
        dist.at(current.node) = current.dist;

        if (current.node == n) {
            if (outMinPrice > current.dist) {
                outMinPrice = current.dist;
                outAmount = 0;
                outMinFlights = INT_MAX;
                outMaxFlights = INT_MIN;
            }
            if (outAmount == 0 || out.at(0).dist == current.dist) {
                out.push_back(current);
            }
            continue;
        }

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
    dist.resize(n + 1, INT_MAX);
    dist.at(1) = 0;

    for (int i = 0; i < m; i++) {
        int a; int b; int c;
        cin >> a; cin >> b; cin >> c;
        adjacencyList.at(a).push_back({b, c});
    }

    dijkstra();

    cout << out.at(0).dist << " ";
    cout << out.size() << " ";

    int minFlights = INT_MAX;
    int maxFlights = INT_MIN;
    for (qElement element : out) {
        minFlights = min(minFlights, element.amountOfFlights);
        maxFlights = max(maxFlights, element.amountOfFlights);
    }
    cout << minFlights << " ";
    cout << maxFlights << " ";
    return 0;
}