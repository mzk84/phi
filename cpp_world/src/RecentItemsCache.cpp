#include "RecentItemsCache.h"

void RecentItemsCache::addItem(const std::string& item) {
	// LRU cache replacement policy
	if (m_size == m_capacity) {
		m_items.erase(item);
		m_orderedItems.pop_back();
		m_size--;
	}
	else {
		m_size++;
	}

	m_orderedItems.push_front(std::make_shared<CacheItem>(item));
	if (m_items.find(item) != m_items.end()) {
		m_orderedItems.erase(m_items[item]);
	}
	m_items[item] = m_orderedItems.begin();

	std::cout << "Added \"" << item << "\" to cache.\n";
}

[[maybe_unused]] const std::list<std::shared_ptr<CacheItem>>& RecentItemsCache::getItems() const {
	printItems();
	return m_orderedItems;
}

void RecentItemsCache::printItems() const {
	std::cout << "Items in cache: ";
	bool first = true;
	for (const auto& i : m_orderedItems) {
		std::cout << (first ? "" : ", ") << i->getValue();
		first = false;
	}
	std::cout << ".\n";
}
