#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int maxAktien; // k
vector<int> prices2;

vector<vector<vector<int>>> dp;

long long solveRecursively(int idx, int price, int amountAktien, bool hasSold) {
	if (idx == prices2.size() && amountAktien == 0) {
		return price;
	}
	if (idx == prices2.size()) {
		return INT_MIN;
	}
	if (amountAktien > maxAktien) {
		return INT_MIN;
	}
	if (dp.at(idx).at(amountAktien).at(hasSold) != INT_MIN) {
		return dp.at(idx).at(amountAktien).at(hasSold);
	}
	long long best = INT_MIN;
	if (! hasSold) {
		best = max(best, solveRecursively(idx + 1, price - prices2.at(idx), amountAktien + 1, false));
	}
	if (amountAktien > 0) {
		best = max(best, solveRecursively(idx + 1, price + prices2.at(idx), amountAktien - 1, true));
	}
	best = max(best, solveRecursively(idx + 1, price, amountAktien, false));
	dp.at(idx).at(amountAktien).at(hasSold) = best;
	return best;
}

long long calculate_max_profit(int n, int k, std::vector<int> prices) {
	/* TODO: Implement your solution here */
	maxAktien = k;
	prices2 = prices;
	dp.resize(n, vector<vector<int>>(k + 1, vector<int>(2, INT_MIN)));
	return solveRecursively(0, 0, 0, false);;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> prices(n);
	for (int i = 0; i < n; i++) cin >> prices[i];
	long long solution = calculate_max_profit(n, k, prices);
	cout << solution << endl;
	return 0;
}
