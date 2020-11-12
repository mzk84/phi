#include "CandyCrush1D.h"

typedef struct {
	char c;
	int n;
} charCounter;

const size_t CRUSH_LIMIT = 3;

std::string CandyCrush1D(const std::string& input) {
	std::stack<charCounter> stack;

	for (const auto& inputChar : input) {
		if (!stack.empty() && stack.top().c != inputChar) {
			if (stack.top().n >= CRUSH_LIMIT) {
				stack.pop();
			}
		}

		if (!stack.empty() && stack.top().c == inputChar) {
			charCounter topObj = stack.top();
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
		if (stack.top().n < CRUSH_LIMIT) {
			for (int cnt = 1; cnt <= stack.top().n; cnt++) {
				result.insert(0, 1, stack.top().c);
			}
		}
		stack.pop();
	}
	return result;
}
