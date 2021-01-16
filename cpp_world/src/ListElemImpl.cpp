#include "ListElemImpl.h"

ListElemImpl::ListElemImpl(): m_name("") {
}

ListElemImpl::ListElemImpl(const ListElemImpl& other): m_name(other.getName()) {
}

ListElemImpl::ListElemImpl(const std::string& name) : m_name(name) {
}

ListElemImpl& ListElemImpl::operator=(const ListElemImpl& other)
{
    if (&other == this) {
        return *this;
    }
    m_name = other.m_name;
    return *this;
}

ListElemImpl::~ListElemImpl() {
}

void ListElemImpl::process(float* buf, size_t num) {
}

const std::string& ListElemImpl::getName() const {
    return m_name;
}
