#include <iostream>
#include <vector>

using namespace std;

vector<int> dp; // index = coin sum | value = how many combinations
vector<int> numbersInput;

int solveRecursively(int targetSum) {
    if (targetSum == 0) {
        return 1;
    }
    if (targetSum < 0) {
        return 0;
    }
    if (dp.at(targetSum) != -1) {
        return dp.at(targetSum);
    }

    int count = 0;
    for (int i = 0; i < numbersInput.size(); i++) {
        count += solveRecursively(targetSum - numbersInput.at(i)) % 1000000007;
        count = count % 1000000007;
    }
    dp.at(targetSum) = count;
    return count;
}

int solveIteratively(int targetSum) {
    dp.at(0) = 1;
    for (int i = 1; i <= targetSum; i++) {
        int count = 0;
        for (int j = 0; j < numbersInput.size(); j++) {
            int prev = i - numbersInput.at(j);
            if (prev < 0 || dp.at(prev) == -1) {
                continue;
            }
            count += dp.at(prev);
            count %= 1000000007;
        }
        dp.at(i) = count;
    }
    return dp.at(targetSum);
}

int main() {
    int n; int x; cin >> n; cin >> x;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbersInput.push_back(c);
    }

    dp.resize(x + 5, -1);
    cout << solveIteratively(x);
    return 0;
}