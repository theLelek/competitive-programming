#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int n; int t;
vector<int> numbersInput;

long long amountOfProducts(long long time) {
    long long products = 0;
    for (int i = 0; i < numbersInput.size(); i++) {
        long long currentAmount = time / numbersInput.at(i);
        products += currentAmount;
        if (currentAmount >= t) return products;
    }
    return products;
}

bool isTrue(long long seconds) {
    long long products = amountOfProducts(seconds);
    return products >= t;
}

long long firstTrue() {
    long long l = 0;
    long long r = LONG_LONG_MAX;
    while (l < r) {
        long long m = l + (r - l) / 2;
        if (isTrue(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return r;
}

int main() {
    cin >> n; cin >> t;

    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbersInput.push_back(c);
    }


    cout << firstTrue();
//    cout << amountOfProducts(3);
    return 0;
}