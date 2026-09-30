#include <iostream>
#include <vector>

using namespace std;

vector<long long> dp; // index = coin sum | value = how many combinations
vector<int> numbersInput;

// int solveRecursively(int targetSum, int idx) {
//     if (targetSum == 0) {
//         return 1;
//     }
//     if (targetSum < 0) {
//         return 0;
//     }
//     if (idx == numbers.size()) {
//         return 0;
//     }
//     if (dp.at(targetSum).at(idx) != -1) {
//         return dp.at(targetSum).at(idx);
//     }
//
//     int count = 0;
//     for (int i = idx; i < numbers.size(); i++) {
//         count += solveRecursively(targetSum - numbers.at(i), i) % 1000000007;
//         count = count % 1000000007;
//     }
//     dp.at(targetSum).at(idx) = count;
//     return count;
// }

int solveIteratively(int targetSum) {
    dp.assign(targetSum + 5, 0);
    dp.at(0) = 1;
    for (int i = 0; i < numbersInput.size(); i++) {
        // index
        for (int j = 1; j <= targetSum; j++) {
            // targetSum
            int currentNumber = numbersInput.at(i);
            int prev = j - currentNumber;
            if (prev < 0) {
                continue;
            }
            dp.at(j) += dp.at(prev);
            dp.at(j) %= 1000000007;
        }
    }
    return dp.at(targetSum);
}


int main() {
    int n; int x; cin >> n; cin >> x;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        numbersInput.push_back(c);
    }

//    dp.resize(x + 5, vector<int>(n + 5, -1));
    cout << solveIteratively(x);
    return 0;
}