#pragma once

#include <memory>

// ListElem is the base class
struct ListElem {
	
	virtual ~ListElem() = default;
	virtual void process(float* buf, size_t num) = 0;
	
	std::shared_ptr<ListElem> next;
};
