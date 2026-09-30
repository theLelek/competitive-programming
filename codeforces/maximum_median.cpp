#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n; int k;
vector<int> numbersInput;

long long getOperations(int medianIncrease) {
    int medianIdx = numbersInput.size() / 2;
    long long count = 0;
    long medianToSet = numbersInput.at(medianIdx) + medianIncrease;
    for (int i = medianIdx; i < numbersInput.size(); i++) {
        if (numbersInput.at(i) >= medianToSet) {
            continue;
        }

        count += medianToSet - numbersInput.at(i);
    }
    return count;
}

bool isTrue(int m) {
    return getOperations(m) <= ((long long) k);
}

int lastTrue(int l, int r) {
    l--;
    while (l < r) {
        int m = l + (r - l + 1) / 2;

        if (isTrue(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return l;
}


int main() {
    cin >> n; cin >> k;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbersInput.push_back(c);
    }

    sort(numbersInput.begin(), numbersInput.end());

    // last true

    int medianIndex = numbersInput.size() / 2;

    int lastTrueIndex = lastTrue(0, k + 5);

    if (lastTrueIndex == -1) {
        cout << numbersInput.at(medianIndex);
    } else {
        cout << numbersInput.at(medianIndex) + lastTrueIndex;
    }
    return 0;
}