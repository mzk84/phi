#include "CandyCrush1D.h"

typedef struct {
	char c;
	int n;
} CharCounter;

std::string candyCrush1D(const std::string& input) {
    constexpr size_t crushLimit = 3;
	std::stack<CharCounter> stack;

	for (const auto& inputChar : input) {
		if (!stack.empty() && stack.top().c != inputChar) {
			if (stack.top().n >= crushLimit) {
				stack.pop();
			}
		}

		if (!stack.empty() && stack.top().c == inputChar) {
            CharCounter topObj = stack.top();
			topObj.n++;
			stack.pop();
			stack.push(topObj);
		}
		else {
			stack.push({ inputChar, 1 });
		}
	}

	std::string result;
	while (!stack.empty()) {
		if (stack.top().n < crushLimit) {
			for (int cnt = 1; cnt <= stack.top().n; cnt++) {
				result.insert(0, 1, stack.top().c);
			}
		}
		stack.pop();
	}
	return result;
}
