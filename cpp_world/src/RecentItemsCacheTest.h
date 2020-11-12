#include "RecentItemsCache.h"

void RecentItemsCacheTest() {
	std::cout << "\n************************************************************\n";
	std::cout << "Recent Items Cache Test\n\n";

	RecentItemsCache cache(5);
	cache.addItem("string 1");
	cache.addItem("string 2");
	cache.addItem("string 3");

	cache.printItems();

	cache.addItem("string 2");

	cache.printItems();

	cache.addItem("string 4");
	cache.addItem("string 5");
	cache.addItem("string 6");

	cache.printItems();

	cache.addItem("string 1");
	cache.addItem("string 2");

	cache.printItems();
}
