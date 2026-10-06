#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int n; int m; int q;
vector<vector<long long>> floydWarshall;
vector<vector<int>> edges;

void initializeFloyWarshall() {
    floydWarshall.resize(n + 1, vector<long long>(n + 1, LONG_LONG_MAX / 2));
    for (int i = 1; i <= n; i++) {
        floydWarshall.at(i).at(i) = 0;
    }

    for (vector<int> edge : edges) {
        long long currentDistance = floydWarshall.at(edge.at(0)).at(edge.at(1));
        if (currentDistance < edge.at(2)) continue;

        floydWarshall.at(edge.at(0)).at(edge.at(1)) = edge.at(2);
        floydWarshall.at(edge.at(1)).at(edge.at(0)) = edge.at(2);
    }
}

int main() {
    cin >> n; cin >> m; cin >> q;

    for (int i = 0; i < m; i++) {
        int a; int b; int c;
        cin >> a; cin >> b; cin >> c;
        edges.push_back({a, b, c});
    }
    initializeFloyWarshall();


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                long long ans1 = floydWarshall.at(j).at(k);
                long long ans2 = floydWarshall.at(j).at(i) + floydWarshall.at(i).at(k);
                if (ans2 < ans1) {
                    floydWarshall.at(j).at(k) = ans2;
                    floydWarshall.at(k).at(j) = ans2;
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a; int b;
        cin >> a; cin >> b;
        long long ans = floydWarshall.at(a).at(b);
        if (ans == LONG_LONG_MAX / 2) {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}