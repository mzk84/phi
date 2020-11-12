#pragma once
#include "MaxNumOfUniqueChars.h"

void MaxNumOfUniqueCharsTest() {
	std::cout << "\n************************************************************\n";
	std::cout << "Maximum Number of Unique Chars Test\n\n";

	std::cout << "Example 1 (should be 0): " << MaxNumOfUniqueChars("abcdefgh") << "\n";
	std::cout << "Example 2 (should be 5): " << MaxNumOfUniqueChars("abcffghijjcd") << "\n";
}
