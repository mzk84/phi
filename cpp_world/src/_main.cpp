#include "mzk84_commons.h"

#include "LargeFileSortingTest.h"
#include "VisitingTreeTest.h"
#include "PatternExpansionTest.h"
#include "BinarySearchTest.h"
#include "CandyCrush1DTest.h"
#include "ListFunctionsTest.h"
#include "MaxNumOfUniqueCharsTest.h"
#include "MyBinarySearchTreeTest.h"
#include "MyListTest.h"
#include "RecentItemsCacheTest.h"

void getAllCombinations(const std::string& input) {
    for (auto pos = 0; pos < input.length(); pos++) {
        if (input[pos] == '?') {
            std::cout << "1";
            getAllCombinations(input.substr(pos));
            std::cout << "0";
            getAllCombinations(input.substr(pos));
        } else {
            std::cout << input[pos];
        }
    }
}

int main() {
	const std::vector<std::function<void(void)>> testFunctions = {
		LargeFileSortingTest,
		VisitingTreeTest
	};

	for (const auto& testFunction : testFunctions)
		testFunction();

	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
