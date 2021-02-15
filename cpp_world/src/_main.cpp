#include "mzk84_commons.h"

#include "LargeFileSortingTest.h"
#include "VisitingTreeTest.h"

#include "BinarySearchTest.h"
#include "CandyCrush1DTest.h"
#include "ListFunctionsTest.h"
#include "MaxNumOfUniqueCharsTest.h"
#include "MyBinarySearchTreeTest.h"
#include "MyListTest.h"
#include "RecentItemsCacheTest.h"

int main() {
	std::cout << "\"Hello, World!\"\n";

	const std::vector<std::function<void(void)>> testFunctions = {
		LargeFileSortingTest,
		VisitingTreeTest
	};

	for (const auto& testFunction : testFunctions)
		testFunction();

	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
