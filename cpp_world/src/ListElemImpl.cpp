#include "ListElemImpl.h"

ListElemImpl::ListElemImpl(std::string name) : m_name(std::move(name)) {
}

ListElemImpl::ListElemImpl(const ListElemImpl& other): m_name(other.getName()) {
}

ListElemImpl& ListElemImpl::operator=(const ListElemImpl& other) {
    if (&other == this) {
        return *this;
    }
    m_name = other.m_name;
    return *this;
}

void ListElemImpl::process(float* buf, size_t num) {
}

const std::string& ListElemImpl::getName() const {
    return m_name;
}
