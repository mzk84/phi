#include "BinarySearch.h"

std::optional<size_t> binarySearch(const std::vector<int>& collection, int value) {

	size_t lowerBound = 0, upperBound = collection.size(), currentIdx = 0;
	while (lowerBound <= upperBound) {
		currentIdx = lowerBound + (upperBound - lowerBound) / 2;
		std::cout << "Checking element at index " << currentIdx << "\n";
		if (collection[currentIdx] > value) {
			upperBound = currentIdx - 1;
		}
		else if (collection[currentIdx] < value) {
			lowerBound = currentIdx + 1;
		}
		else {
			return currentIdx;
		}
	}
	return std::nullopt;
} 