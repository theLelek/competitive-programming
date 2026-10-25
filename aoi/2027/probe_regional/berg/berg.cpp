#include "berg.h"
#include <deque>

using namespace std;

struct element {

  int value;
  int index;
  int amountOfEqualElements;

  element(int value, int index, int amount_of_equal_elements)
    : value(value),
      index(index),
      amountOfEqualElements(amount_of_equal_elements) {
  }
};

long long solve(vector<int> numbers) {
  long long ans = 0;

  deque<element> monotonicStack = {};
  for (int i = 0; i < numbers.size(); i++) {
    while (monotonicStack.size() != 0 && monotonicStack.back().value < numbers.at(i)) {
      monotonicStack.pop_back();
    }
    int amountOfEqualElements = monotonicStack.size() != 0
    && monotonicStack.back().value == numbers.at(i)
    ? 1 + monotonicStack.back().amountOfEqualElements
    : 0;

    monotonicStack.push_back(element(numbers.at(i), i, amountOfEqualElements));

    if (monotonicStack.size() < 2) continue;

    if (monotonicStack.back().value == monotonicStack.at(monotonicStack.size() - 2).value) {
      ans += monotonicStack.back().amountOfEqualElements;
    }
  }

  return ans * 2;
}
