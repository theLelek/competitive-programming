#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> numbers;

int getMinPower(int launchCoordinate) {



    return -1;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbers.push_back(c * 2);
    }
    sort(numbers.begin(), numbers.end());
    for (int i = 1; i < n; i++) {
        numbers.push_back((numbers.at(i - 1) + numbers.at(i)) / 2);
    }
    sort(numbers.begin(), numbers.end());


    return 0;
}
