#include "PatternExpansion.h"

#include <string>
#include <vector>

void expandPattern(std::vector<std::string>& output, std::string input, size_t currentPosition) {
    if (currentPosition == input.size()) {
        output.push_back(input);
        return;
    }
    if (input[currentPosition] == '?') {
        input[currentPosition] = '0';
        expandPattern(output, input, currentPosition + 1);
        input[currentPosition] = '1';
        expandPattern(output, input, currentPosition + 1);
    } else {
        expandPattern(output, input, currentPosition + 1);
    }
}