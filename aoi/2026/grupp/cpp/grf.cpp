#include <vector>
#include "grf.h"<2
#include <iostream>
#include <limits.h>
#include <stack>

using namespace std;

bool fit(int amount, vector<int> &smaller, vector<int> &larger) {
    int count = 0;

    for (int i = 0; i < smaller.size(); i++) {
        if (smaller.at(i) < count) continue;
        if (larger.at(i) >= amount - 1 - count) {
            count++;
        }
    }
    return count >= amount;
}

int solve(int n, vector<int> smaller, vector<int> larger) {
    // last true
    int l = -1;
    int r = n + 5;
    while (l < r) {
        int m = l + (r - l + 1) / 2;

        if (fit(m, smaller, larger)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    if (l == -1) {
        return 0;
    } else {
        return l;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> smaller(n), larger(n);
    for (int i = 0; i < n; i++) cin >> smaller[i];
    for (int i = 0; i < n; i++) cin >> larger[i];
    int solution = solve(n, smaller, larger);
    cout << solution << endl;


//    cout << fit(4, smaller, larger);
    return 0;
}

