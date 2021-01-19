#pragma once

#include "ListElem.h"

#include <string>

class ListElemImpl : public ListElem {

public:
    explicit ListElemImpl(std::string name);
    ListElemImpl(const ListElemImpl& other);
	ListElemImpl& operator=(const ListElemImpl& other);
	~ListElemImpl() override {};

	void process(float* buf, size_t num) override;

	[[nodiscard]] const std::string& getName() const;

private:
	std::string m_name;
};
