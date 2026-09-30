
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

vector<int> numbersInput;
vector<int> segmentTree;

int getMin(int from, int to, int index) {
    if (from == to) {
        segmentTree.at(index) = numbersInput.at(from);
        return numbersInput.at(from);
    }

    int left = getMin(from, from + (to - from) / 2, index * 2);
    int right = getMin(from + (to - from) / 2 + 1, to, index * 2 + 1);
    segmentTree.at(index) = min(left, right);
    return min(left, right);
}

vector<int> buildSegmentTree() {
    segmentTree.resize(numbersInput.size() * 4, INT_MIN);
    getMin(0, numbersInput.size() - 1, 1);

    return segmentTree;
}

int answer(int nodeFrom, int nodeTo, int index, int const from, int const to) {
    if (nodeFrom >= from && nodeTo <= to) {
        return segmentTree.at(index);
    }
    if (nodeFrom > to || nodeTo < from) {
        return INT_MAX;
    }

    int m = nodeFrom + (nodeTo - nodeFrom) / 2;
    int l = answer(nodeFrom, m, index * 2, from, to);
    int r = answer(m + 1, nodeTo, index * 2 + 1, from, to);
    return min(l, r);
}

int update(int nodeFrom, int nodeTo, int index, int targetIndex, int toSet) {
    if (nodeFrom == nodeTo && nodeFrom == targetIndex) {
        segmentTree.at(index) = toSet;
        return toSet;
    }
    if (nodeFrom > targetIndex || nodeTo < targetIndex) {
        return segmentTree.at(index);
//        return INT_MAX;
    }

    int m = nodeFrom + (nodeTo - nodeFrom) / 2;
    int l = update(nodeFrom, m, index * 2, targetIndex, toSet);
    int r = update(m + 1, nodeTo, index * 2 + 1, targetIndex, toSet);

    segmentTree.at(index) = min(l, r);
    return min(l, r);
}

int main() {
    int n; int q;
    cin >> n; cin >> q;


    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbersInput.push_back(c);
    }
    buildSegmentTree();
//    cout << answer(0, numbers.size() - 1, 1, 6, 7);

    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        int a; int b;
        cin >> a; cin >> b;
        if (type == 1) {
            // update
            update(0, numbersInput.size() - 1, 1, a - 1, b);
        } else {
            // answer
            cout << answer(0, numbersInput.size() - 1, 1, a - 1, b - 1) << "\n";
        }
    }

    return 0;
}