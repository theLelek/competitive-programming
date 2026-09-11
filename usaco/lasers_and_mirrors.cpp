#include <algorithm>
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
};

struct element {
    coord current;
    coord previous;
    int distance;
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
    int direction2 = getDirection(current.previous, current.current) == getDirection(current.current, next);
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
    int n;
    int x1; int y1;
    int x2; int y2;
    cin >> n;
    cin >> x1; cin >> y1;
    cin >> x2; cin >> y2;


    vector<coord> coords;

    for (int i = 0; i < n; i++) {
        int x; int y;
        cin >> x; cin >> y;
        coord c = coord(x, y);
        coords.push_back(c);
    }
    vector<int> yCoords = substitute(coords, true);
    vector<int> xCoords = substitute(coords, false);
    sort(yCoords.begin(), yCoords.end());
    sort(xCoords.begin(), xCoords.end());

    vector<vector<coord>> columns(100000 + 5);
    vector<vector<coord>> rows(100000 + 5);

    for (int i = 0; i < n; i++) {
        int x = compress(xCoords, xCoords.at(i));
        int y = compress(yCoords, yCoords.at(i));
        coord c = coord(x, y);
        columns.at(x).push_back(c);
        rows.at(y).push_back(c);
    }

    coord target = {compress(xCoords, x2), compress(yCoords, y2)};
    columns.at(compress(xCoords, x2)).push_back(target);
    rows.at(compress(yCoords, y2)).push_back(target);

    coord root = {compress(xCoords, x1), compress(yCoords, y1)};

    deque<element> q = {};
    q.push_back({root, root, 0});

    while (! q.empty()) {
        element current = q.front();
        if (current.current == target) {
            break;
        }
        q.pop_front();
        for (int i = 0; i < columns.at(current.current.x).size(); i++) {
            coord currentCoord = columns.at(current.current.x).at(i);
            add(q, current, currentCoord);
        }
        for (int i = 0; i < rows.at(current.current.y).size(); i++) {
            coord currentCoord = columns.at(current.current.y).at(i);
            add(q, current, currentCoord);
        }
    }

    if (q.size() == 0) {
        cout << -1;
    } else {
        cout << q.front().distance;
    }
    return 0;
}