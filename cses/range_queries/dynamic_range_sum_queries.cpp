#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

vector<int> numbersInput;
vector<long long> segmentTree;

long long buildSegmentTree(int nodeFrom, int nodeTo, int index) {
    if (nodeFrom == nodeTo) {
        segmentTree.at(index) = numbersInput.at(nodeFrom);
        return numbersInput.at(nodeFrom);
    }

    int m = nodeFrom + (nodeTo - nodeFrom) / 2;
    long long l = buildSegmentTree(nodeFrom, m, index * 2);
    long long r = buildSegmentTree(m + 1, nodeTo, index * 2 + 1);
    segmentTree.at(index) = l + r;
    return l + r;
}

long long answer(int nodeFrom, int nodeTo, int index, int from, int to) {
    if (nodeFrom >= from && nodeTo <= to) {
        return segmentTree.at(index);
    }
    if (from > nodeTo || to < nodeFrom) {
        return 0;
    }

    int m = nodeFrom + (nodeTo - nodeFrom) / 2;
    long long l = answer(nodeFrom, m, index * 2, from, to);
    long long r = answer(m + 1, nodeTo, index * 2 + 1, from, to);
    return l + r;
}

long long update(int nodeFrom, int nodeTo, int index, int targetNode, int updatedValue) {
    if (nodeFrom == nodeTo && nodeFrom == targetNode) {
        segmentTree.at(index) = updatedValue;
        return updatedValue;
    }
    if (targetNode > nodeTo || targetNode < nodeFrom) {
        return segmentTree.at(index);
    }


    int m = nodeFrom + (nodeTo - nodeFrom) / 2;
    long long l = update(nodeFrom, m, index * 2, targetNode, updatedValue);
    long long r = update(m + 1, nodeTo, index * 2 + 1, targetNode, updatedValue);

    segmentTree.at(index) = l + r;
    return l + r;
}

int main() {
    int n; int q;
    cin >> n; cin >> q;

    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbersInput.push_back(c);
    }

    segmentTree.resize(numbersInput.size() * 4, INT_MIN / 2);
    buildSegmentTree(0, numbersInput.size() - 1, 1);

//    cout << answer(0, numbers.size() - 1, 1, 1, 3);

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