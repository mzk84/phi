#include "MaxNumOfUniqueChars.h"

size_t countUniqueChars(std::string input) {
	size_t count = 0;
	std::unordered_set<char> uniqueChars;
	std::pair<std::unordered_set<char>::iterator, bool> insertedRes;
	for (size_t i = 0; i <= input.length(); ++i) {
		insertedRes = uniqueChars.insert(input[i]);
		if (insertedRes.second == true) {
			count++;
		}
	}
	return count;
}

std::string MaxNumOfUniqueChars(const std::string& input) {
	size_t maxNum = 0;
	std::unordered_map<char, size_t> hashMapCharToPos;
	for (size_t i = 0; i < input.length(); ++i) {
		if (hashMapCharToPos.find(input[i]) != hashMapCharToPos.end()) {
			size_t firstIdx = hashMapCharToPos[input[i]];
			maxNum = std::max(maxNum, countUniqueChars(input.substr(firstIdx + 1, i - firstIdx - 1)));
		}
		hashMapCharToPos[input[i]] = i;
	}
	return std::to_string(maxNum);
}
