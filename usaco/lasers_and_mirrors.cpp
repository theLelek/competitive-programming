#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct coord {
    int x;
    int y;

    bool operator==(const coord &other) {
        return other.x == x && other.y == y;
    }

    coord(int x1, int y1) {
        x = x1;
        y = y1;
    }
};

struct element {
    coord current;
    coord previous;
    int distance;

    element(coord current, coord previous, int distance)
        : current(current), previous(previous), distance(distance) {}
};

int getDirection(coord &a, coord &b) {
    if (a.y - b.y > 0) {
        return 0; // up
    }
    if (b.y - a.y > 0) {
        return 2; // down
    }
    if (a.x - b.x > 0) {
        return 3; // left
    }
    if (b.x - a.x > 0) {
        return 1; // right;
    }
    return -1; // equal
}

void add(deque<element> &q, element &current, coord &next) {
    int direction1 = getDirection(current.previous, current.current);
    int direction2 = getDirection(current.current, next);
    if (direction1 == direction2 || direction1 == -1) {
        q.push_front({next, current.current, current.distance});
    } else {
        q.push_back({next, current.current, current.distance + 1});
    }
}

vector<int> substitute(vector<coord> &coords, bool pickX) {
    vector<int> out;
    for (int i = 0; i < coords.size(); i++) {
        if (pickX) {
            out.push_back(coords.at(i).x);
        } else {
            out.push_back(coords.at(i).y);
        }
    }
    return out;
}

int compress(vector<int> &list, int target) {
    int l = 0;
    int r = list.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        if (list.at(m) >= target) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return r;
}

int main() {
    ifstream in("lasers.in");
    ofstream out("lasers.out");

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());

    int n;
    int x1; int y1;
    int x2; int y2;
    cin >> n;
    cin >> x1; cin >> y1;
    cin >> x2; cin >> y2;

    vector<coord> coords = {{x1, y1}, {x2, y2}};

    for (int i = 0; i < n; i++) {
        int x; int y;
        cin >> x; cin >> y;
        coord c = coord(x, y);
        coords.push_back(c);
    }

    vector<int> yCoordsCompressor = substitute(coords, false);
    vector<int> xCoordsCompressor = substitute(coords, true);
    sort(yCoordsCompressor.begin(), yCoordsCompressor.end());
    sort(xCoordsCompressor.begin(), xCoordsCompressor.end());

    // now coords are compresses

    vector<vector<coord>> columns(100000 + 5);
    vector<vector<coord>> rows(100000 + 5);

    for (int i = 0; i < n; i++) {
        int x = compress(xCoordsCompressor, coords.at(i).x);
        int y = compress(yCoordsCompressor, coords.at(i).y);
        coord c = coord(x, y);
        columns.at(x).push_back(c);
        rows.at(y).push_back(c);
    }

    coord target = {compress(xCoordsCompressor, x2), compress(yCoordsCompressor, y2)};
    columns.at(compress(xCoordsCompressor, x2)).push_back(target);
    rows.at(compress(yCoordsCompressor, y2)).push_back(target);

    coord root = {compress(xCoordsCompressor, x1), compress(yCoordsCompressor, y1)};

    deque<element> q = {};
    q.push_back({root, root, 0});
    vector<bool> visitedRows(n + 5);
    vector<bool> visitedColumns(n + 5);

    while (!q.empty()) {
        element current = q.front();

        if (current.current == target) {
            break;
        }

        q.pop_front();

        if (!visitedColumns[current.current.x]) {
            for (int i = 0; i < columns[current.current.x].size(); i++) {
                coord currentCoord = columns[current.current.x][i];
                add(q, current, currentCoord);
            }
            visitedColumns[current.current.x] = true;
        }

        if (!visitedRows[current.current.y]) {
            for (int i = 0; i < rows[current.current.y].size(); i++) {
                coord currentCoord = rows[current.current.y][i];
                add(q, current, currentCoord);
            }
            visitedRows[current.current.y] = true;
        }
    }

    if (q.size() == 0) {
        cout << -1;
    } else {
        cout << q.front().distance;
    }
    return 0;
}