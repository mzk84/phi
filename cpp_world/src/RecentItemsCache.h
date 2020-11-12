#pragma once

#include "_includes.h"

class CacheItem {
private:
	std::string m_value;

public:
	explicit CacheItem(std::string value) : m_value(std::move(value)) {}
	const std::string& getValue() const { return m_value; }
};

class RecentItemsCache {
private:
	std::list<std::shared_ptr<CacheItem>> m_orderedItems;
	std::unordered_map<std::string, std::list<std::shared_ptr<CacheItem>>::const_iterator> m_items;
	size_t m_capacity;
	size_t m_size;

public:
	explicit RecentItemsCache(size_t capacity) : m_capacity(capacity), m_size(0) {}
	void addItem(const std::string& item);
	[[maybe_unused]] const std::list<std::shared_ptr<CacheItem>>& getItems() const;
	void printItems() const;
};
