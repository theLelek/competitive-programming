#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> numbersInput;
vector<bool> dp;


// void solveRecursively(int idx, int currentSum) {
//     if (idx == numbers.size()) {
//         out.insert(currentSum);
//         return;
//     }
//
//     solveRecursively(idx + 1, currentSum + numbers.at(idx));
//     solveRecursively(idx + 1, currentSum);
// }

void addElements(vector<bool> &a, vector<bool> b) {
    for (int i = 0; i < b.size(); i++) {
        if (b.at(i)) {
            a.at(i) = true;
        }
    }
}

void solveIteratively(int n) {
//    dp.insert(numbers.at(0));
    dp.at(numbersInput.at(0)) = true;
    for (int i = 1; i < n; i++) {
        vector<bool> holder(dp.size());
        int ans1 = numbersInput.at(i);
        holder.at(ans1) = true;

        for (int i = 0; i < dp.size(); i++) {
            if (! dp.at(i)) continue;
            int ans2 = i;
            int ans3 = ans1 + ans2;
            holder.at(ans3) = true;
        }
        addElements(dp, holder);
    }
}


int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int c; cin >> c; numbersInput.push_back(c);
    }
    dp.resize(100 * 1000 + 5);
    solveIteratively(n);

    vector<int> out;
    for (int i = 0; i < dp.size(); i++) {
        if (! dp.at(i)) continue;
        out.push_back(i);
    }

    cout << out.size() << "\n";
    for (int i = 0; i < out.size(); i++) {
        cout << out.at(i) << " ";
    }
    return 0;
}
