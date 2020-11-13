#include "_mzk84_utils.h"

#include "CandyCrush1DTest.h"
#include "MaxNumOfUniqueCharsTest.h"
#include "RecentItemsCacheTest.h"
#include "VisitingTreeTest.h"

int main() {
	std::cout << "\"Hello, World!\"\n";

	const std::vector<std::function<void(void)>> testFunctions = {
		CandyCrush1DTest,
		MaxNumOfUniqueCharsTest,
		RecentItemsCacheTest,
		VisitingTreeTest
	};

	for (const auto& testFunction : testFunctions)
		testFunction();

	return 0;
}
