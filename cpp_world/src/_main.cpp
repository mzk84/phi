#include "mzk84_commons.h"

#include "CandyCrush1DTest.h"
#include "LargeFileSortingTest.h"
#include "MaxNumOfUniqueCharsTest.h"
#include "RecentItemsCacheTest.h"
#include "VisitingTreeTest.h"

#include "ListTestSuite.h"

int main() {
	std::cout << "\"Hello, World!\"\n";

	const std::vector<std::function<void(void)>> testFunctions = {
		CandyCrush1DTest,
		LargeFileSortingTest,
		MaxNumOfUniqueCharsTest,
		RecentItemsCacheTest,
		VisitingTreeTest
	};

	for (const auto& testFunction : testFunctions)
		testFunction();
		
	// Run the suite of testss
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();

	return 0;
}
