#pragma once

#include "ListElem.h"

#include <string>

class ListElemImpl : public ListElem {

public:
	ListElemImpl();
	ListElemImpl(const ListElemImpl& other);
	explicit ListElemImpl(const std::string& name);
	ListElemImpl& operator=(const ListElemImpl& other);
	~ListElemImpl() override;

	void process(float* buf, size_t num) override;

	const std::string& getName() const;

private:
	std::string m_name;
};
