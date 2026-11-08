#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int n; int m;
vector<pair<long long, long long>> numbers2;

bool check(long long space) {
    long long currentCow = 0;
    long long previousCowIndex = LONG_LONG_MIN / 2; // todo
    for (auto range : numbers2) {
        long long from = range.first;
        long long to = range.second;
        long long intervalSize = to - from + 1;
        if (previousCowIndex + space > range.first) {
            from = previousCowIndex + space;
            intervalSize = to - from + 1;
        }
        if (from > to) {
            continue;
        }
        long long fittingCows = 1 + (intervalSize - 1) / space;
        currentCow += fittingCows;

        previousCowIndex = (fittingCows - 1) * space + from;
    }
    return currentCow >= n;
}

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("socdist.in", "r", stdin);
//     freopen("socdist.out", "w", stdout);
// #endif
    cin >> n; cin >> m;
    for (int i = 0; i < m; i++) {
        long long a; long long b;
        cin >> a; cin >> b;
        numbers2.push_back({a, b});
    }
    sort(numbers2.begin(), numbers2.end());

    // last true:
    long long l = 0;
    long long r = LONG_LONG_MAX / 2;
//    long long r = 10;
    while (l < r) {
        long long m = l + (r - l + 1) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    cout << l;
    return 0;
}