// DIESE DATEI NICHT BEARBEITEN
#include <iostream>
#include <vector>
#include "berg.h"

using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;
  long long res = solve(a);
  cout << res << endl;
  return 0;
}
