#include <algorithm>
#include <vector>

using namespace std;

struct element {
    int value1;
    int value2;

    bool operator<(element e) {
        return value1 < e.value1;
    }
};

int main() {

    vector<element> list = {{1, 2, }, {0, 1},{1, 0}, {10, -1}};
    sort(list.begin(), list.end());
    return 0;
}